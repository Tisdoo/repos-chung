#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <climits>
#include <iomanip>
using namespace std;

struct Process {
    string name;
    int arrival, burst;
    int start = 0, finish = 0, waiting = 0, turnaround = 0;
};

void printGanttChart(const vector<pair<string, pair<int, int>>>& gantt, ofstream& out) {
    out << "\nS? ?? Gantt:\n";

    // V? timeline
    out << "Time: ";
    for (const auto& entry : gantt) {
        out << entry.second.first << "---[" << entry.first << "]---";
    }
    out << gantt.back().second.second << "\n";

    // V? thanh Gantt
    out << "Gantt: |";
    for (const auto& entry : gantt) {
        int duration = entry.second.second - entry.second.first;
        out << " " << entry.first << " (" << duration << ") |";
    }
    out << "\n\n";
}

bool cmpArrival(const Process& a, const Process& b) {
    return a.arrival < b.arrival;
}

bool cmpBurst(const Process& a, const Process& b) {
    return a.burst < b.burst;
}

void FCFS(vector<Process> p, ofstream& out) {
    sort(p.begin(), p.end(), cmpArrival);
    int time = 0;
    vector<pair<string, pair<int, int>>> gantt;

    for (auto& pr : p) {
        pr.start = max(time, pr.arrival);
        pr.finish = pr.start + pr.burst;
        pr.waiting = pr.start - pr.arrival;
        pr.turnaround = pr.finish - pr.arrival;

        gantt.push_back({ pr.name, {pr.start, pr.finish} });
        time = pr.finish;
    }

    out << "=== FCFS Scheduling ===\n";
    out << "Name\tArrival\tBurst\tStart\tFinish\tWaiting\tTurnaround\n";
    for (auto& pr : p)
        out << pr.name << "\t" << pr.arrival << "\t" << pr.burst << "\t" << pr.start << "\t" << pr.finish
        << "\t" << pr.waiting << "\t" << pr.turnaround << "\n";

    printGanttChart(gantt, out);
}

void SJF(vector<Process> p, ofstream& out) {
    vector<Process> done;
    int time = 0;
    vector<pair<string, pair<int, int>>> gantt;

    while (!p.empty()) {
        vector<Process> ready;
        for (auto& pr : p)
            if (pr.arrival <= time)
                ready.push_back(pr);

        if (ready.empty()) {
            time++;
            continue;
        }

        auto shortest = min_element(ready.begin(), ready.end(), cmpBurst);
        Process next = *shortest;
        next.start = time;
        next.finish = time + next.burst;
        next.waiting = next.start - next.arrival;
        next.turnaround = next.finish - next.arrival;

        gantt.push_back({ next.name, {next.start, next.finish} });
        time = next.finish;

        done.push_back(next);
        p.erase(remove_if(p.begin(), p.end(), [&](Process& pr) { return pr.name == next.name; }), p.end());
    }

    out << "=== SJF Scheduling ===\n";
    out << "Name\tArrival\tBurst\tStart\tFinish\tWaiting\tTurnaround\n";
    for (auto& pr : done)
        out << pr.name << "\t" << pr.arrival << "\t" << pr.burst << "\t" << pr.start << "\t" << pr.finish
        << "\t" << pr.waiting << "\t" << pr.turnaround << "\n";

    printGanttChart(gantt, out);
}

void STRF(vector<Process> p, ofstream& out) {
    int n = p.size();
    vector<int> remain(n);
    vector<bool> isDone(n, false);
    for (int i = 0; i < n; ++i) remain[i] = p[i].burst;

    int time = 0, completed = 0;
    vector<pair<string, pair<int, int>>> gantt;
    int prevProcess = -1;

    while (completed < n) {
        int shortest = -1;
        int minRemain = INT_MAX;

        for (int i = 0; i < n; ++i) {
            if (p[i].arrival <= time && !isDone[i] && remain[i] < minRemain && remain[i] > 0) {
                minRemain = remain[i];
                shortest = i;
            }
        }

        if (shortest == -1) {
            time++;
            continue;
        }

        if (remain[shortest] == p[shortest].burst)
            p[shortest].start = time;

        // Ghi nh?n s? thay ??i process trong Gantt chart
        if (shortest != prevProcess) {
            if (prevProcess != -1) {
                gantt.back().second.second = time;
            }
            gantt.push_back({ p[shortest].name, {time, time + 1} });
            prevProcess = shortest;
        }
        else {
            gantt.back().second.second = time + 1;
        }

        remain[shortest]--;
        time++;

        if (remain[shortest] == 0) {
            isDone[shortest] = true;
            p[shortest].finish = time;
            p[shortest].turnaround = p[shortest].finish - p[shortest].arrival;
            p[shortest].waiting = p[shortest].turnaround - p[shortest].burst;
            completed++;
        }
    }

    out << "=== STRF (Shortest Time Remaining First) ===\n";
    out << "Name\tArrival\tBurst\tStart\tFinish\tWaiting\tTurnaround\n";
    for (auto& pr : p)
        out << pr.name << "\t" << pr.arrival << "\t" << pr.burst << "\t" << pr.start
        << "\t" << pr.finish << "\t" << pr.waiting << "\t" << pr.turnaround << "\n";

    printGanttChart(gantt, out);
}

void RoundRobin(vector<Process> p, int quantum, ofstream& out) {
    vector<int> remain(p.size());
    int time = 0;
    for (int i = 0; i < p.size(); ++i) remain[i] = p[i].burst;

    vector<bool> started(p.size(), false);
    vector<pair<string, pair<int, int>>> gantt;
    queue<int> q;
    int current = -1;
    int remainingQuantum = 0;

    while (true) {
        // Thêm các process m?i vào hàng ??i
        for (int i = 0; i < p.size(); ++i) {
            if (p[i].arrival == time && remain[i] > 0) {
                q.push(i);
            }
        }

        // N?u có process ?ang ch?y và h?t quantum ho?c hoàn thành
        if (current != -1 && (remainingQuantum == 0 || remain[current] == 0)) {
            if (remain[current] > 0) {
                q.push(current); // ??a l?i vào hàng ??i n?u ch?a hoàn thành
            }
            else {
                p[current].finish = time;
                p[current].turnaround = p[current].finish - p[current].arrival;
                p[current].waiting = p[current].turnaround - p[current].burst;
            }
            current = -1;
        }

        // N?u không có process nào ?ang ch?y và hàng ??i không r?ng
        if (current == -1 && !q.empty()) {
            current = q.front();
            q.pop();
            remainingQuantum = quantum;
            if (!started[current]) {
                p[current].start = time;
                started[current] = true;
            }
            // Ghi nh?n vào Gantt chart
            if (gantt.empty() || gantt.back().first != p[current].name) {
                gantt.push_back({ p[current].name, {time, time + 1} });
            }
            else {
                gantt.back().second.second = time + 1;
            }
        }

        // Ki?m tra ?i?u ki?n k?t thúc
        bool done = true;
        for (int i = 0; i < p.size(); ++i) {
            if (remain[i] > 0) {
                done = false;
                break;
            }
        }
        if (done) break;

        // Th?c thi process hi?n t?i
        if (current != -1 && remain[current] > 0) {
            remain[current]--;
            remainingQuantum--;
            // C?p nh?t Gantt chart
            gantt.back().second.second = time + 1;
        }

        time++;
    }

    out << "=== Round Robin (Quantum = " << quantum << ") ===\n";
    out << "Name\tArrival\tBurst\tFinish\tWaiting\tTurnaround\n";
    for (auto& pr : p)
        out << pr.name << "\t" << pr.arrival << "\t" << pr.burst << "\t" << pr.finish
        << "\t" << pr.waiting << "\t" << pr.turnaround << "\n";

    printGanttChart(gantt, out);
}

int main() {
    ifstream in("TextFile1.txt");
    ofstream out("output.txt");

    if (!in) {
        cerr << "Không th? m? file TextFile1.txt\n";
        return 1;
    }

    int n;
    in >> n;
    vector<Process> processes(n);

    for (int i = 0; i < n; ++i) {
        in >> processes[i].name >> processes[i].arrival >> processes[i].burst;
    }

    FCFS(processes, out);
    SJF(processes, out);
    STRF(processes, out);
    RoundRobin(processes, 2, out); // Quantum = 2

    cout << "?ã ghi k?t qu? ra file output.txt\n";
    return 0;
}