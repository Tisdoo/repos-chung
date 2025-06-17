#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

struct Process {
    int id;
    int at; // arrival time
    int bt; // burst time
    int wt; bool completed = false;
};

// Sắp xếp theo thời gian đến (arrival time)
bool cmp(Process a, Process b) {
    return a.at < b.at;
}

int main() {
    ifstream input("TextFile1.txt");
    ofstream output("Output-Build");
    if (!input.is_open()) {
        cout << "Khong tim thay file ";
        return 1;
    }
    int n;
    input >> n;
    Process* p = new Process[n];




    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;
        input >> p[i].at >> p[i].bt;
    }

    sort(p, p + n, cmp); // Sắp xếp theo thời gian đến

    int time = 0;
    for (int i = 0; i < n; i++) {
        if (time < p[i].at)
            time = p[i].at; // Nếu CPU rảnh thì đợi đến lúc tiến trình tới

        p[i].wt = time - p[i].at;
        time += p[i].bt;
        
    }

    output << "P\tAT\tBT\tWT\n";
    for (int i = 0; i < n; i++) {
        output << "P" << p[i].id << "\t" << p[i].at << "\t"
            << p[i].bt << "\t" << p[i].wt << "\n" ;
    }
    double total_wt = 0;
    for (int i = 0; i < n; i++) {
        total_wt += p[i].wt;
    }  output << "FCFS tg doi TB ";
    double avg_wt = total_wt / n; output << avg_wt<<endl;





    int completedCount = 0, currentTime = 0;
    while (completedCount < n) {
        int idx = -1;
        int minBT = 10000000000000000000;
        for (int i = 0; i < n; i++) {
            if (!p[i].completed && p[i].at <= currentTime && p[i].bt < minBT) {
                minBT = p[i].bt;
                idx = i;
            }
        }

        if (idx == -1) { // Không có tiến trình sẵn sàng
            currentTime++;
        }
        else {
            p[idx].wt = currentTime - p[idx].at;
            currentTime += p[idx].bt;
      
            p[idx].completed = true;
            completedCount++;
        }
    }

    output << "P\tAT\tBT\tWT\n";
    for (int i = 0; i < n; i++) {
        output << "P" << p[i].id << "\t" << p[i].at << "\t"
            << p[i].bt << "\t" << p[i].wt << "\n";
    }

    double sjl_total_wt = 0;
    for (int i = 0; i < n; i++) {
        sjl_total_wt += p[i].wt;
    }
    output << "SJL tg doi TB ";
    double sjl_avg_wt = sjl_total_wt / n; output << sjl_avg_wt << endl;

    input.close();
    output.close();

  
    return 0;
}
