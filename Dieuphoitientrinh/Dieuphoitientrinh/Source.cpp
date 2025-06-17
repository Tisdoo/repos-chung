#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

struct Process {
    int id;
    int at; // arrival time
    int bt; // burst time
    int wt, tat;
};

// Sắp xếp theo thời gian đến (arrival time)
bool cmp(Process a, Process b) {
    return a.at < b.at;
}

int main() {
    ifstream input("input.txt");
    ofstream output("Output-Build");
    if (!input.is_open()) {
        cout << "Khong tim thay file input.txt!";
        return 1;
    }
    int n;
    input >> n;
    Process* p = new Process[n];




    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;
        input >> p[i].at >> p[i].bt;
    }

    sort(p, p + n, cmp); // Sắp xếp theo arrival time

    int time = 0;
    for (int i = 0; i < n; i++) {
        if (time < p[i].at)
            time = p[i].at; // Nếu CPU rảnh thì đợi đến lúc tiến trình tới

        p[i].wt = time - p[i].at;
        time += p[i].bt;
        p[i].tat = p[i].wt + p[i].bt;
    }

    output << "P\tAT\tBT\tWT\tTAT\n";
    for (int i = 0; i < n; i++) {
        output << "P" << p[i].id << "\t" << p[i].at << "\t"
            << p[i].bt << "\t" << p[i].wt << "\t" << p[i].tat << "\n";
    }

    input.close();
    output.close();

    cout << "Hoan thanh! Co Arrival Time. Ket qua luu trong output.txt\n";
    return 0;
}
