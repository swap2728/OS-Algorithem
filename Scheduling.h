#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
#include <queue>
// #include "OS.h"
using namespace std;


class Scheduling  {
public:
    // First Come First Serve (FCFS)
    void fcfs(vector<int> arrival, vector<int> burst) {
        cout << "First Come First Serve (FCFS) Scheduling:" << endl;
        int n = arrival.size();
        vector<int> waitingTime(n), turnAroundTime(n);

        waitingTime[0] = 0;
        for (int i = 1; i < n; i++) {
            waitingTime[i] = waitingTime[i - 1] + burst[i - 1] - (arrival[i] - arrival[i - 1]);
            if (waitingTime[i] < 0)
                waitingTime[i] = 0;
        }

        for (int i = 0; i < n; i++) {
            turnAroundTime[i] = waitingTime[i] + burst[i];
        }

        printMetrics(arrival, burst, waitingTime, turnAroundTime);
    }

    // Shortest Job First (SJF)
    void sjf(vector<int> arrival, vector<int> burst) {
        cout << "\nShortest Job First (SJF) Scheduling:" << endl;
        int n = arrival.size();
        vector<int> waitingTime(n), turnAroundTime(n), remainingBurst = burst;
        vector<bool> isCompleted(n, false);
        int completed = 0, currentTime = 0;

        while (completed < n) {
            int idx = -1;
            for (int i = 0; i < n; i++) {
                if (arrival[i] <= currentTime && !isCompleted[i]) {
                    if (idx == -1 || remainingBurst[i] < remainingBurst[idx])
                        idx = i;
                }
            }

            if (idx != -1) {
                currentTime += burst[idx];
                turnAroundTime[idx] = currentTime - arrival[idx];
                waitingTime[idx] = turnAroundTime[idx] - burst[idx];
                isCompleted[idx] = true;
                completed++;
            } else {
                currentTime++;
            }
        }

        printMetrics(arrival, burst, waitingTime, turnAroundTime);
    }

    // Priority Scheduling
    void priorityScheduling(vector<int> arrival, vector<int> burst, vector<int> priority) {
        cout << "\nPriority Scheduling:" << endl;
        int n = arrival.size();
        vector<int> waitingTime(n), turnAroundTime(n);
        vector<bool> isCompleted(n, false);
        int completed = 0, currentTime = 0;

        while (completed < n) {
            int idx = -1;
            for (int i = 0; i < n; i++) {
                if (arrival[i] <= currentTime && !isCompleted[i]) {
                    if (idx == -1 || priority[i] < priority[idx])
                        idx = i;
                }
            }

            if (idx != -1) {
                currentTime += burst[idx];
                turnAroundTime[idx] = currentTime - arrival[idx];
                waitingTime[idx] = turnAroundTime[idx] - burst[idx];
                isCompleted[idx] = true;
                completed++;
            } else {
                currentTime++;
            }
        }

        printMetrics(arrival, burst, waitingTime, turnAroundTime, &priority);
    }

    // Round Robin Scheduling
    // void roundRobin(vector<int> arrival, vector<int> burst, int quantum) {
    //     cout << "\nRound Robin Scheduling:" << endl;
    //     int n = arrival.size();
    //     vector<int> waitingTime(n), turnAroundTime(n), remainingBurst = burst;
    //     queue<int> readyQueue;
    //     int currentTime = 0, completed = 0;

    //     for (int i = 0; i < n; i++) {
    //         if (arrival[i] == 0)
    //             readyQueue.push(i);
    //     }

    //     while (completed < n) {
    //         if (!readyQueue.empty()) {
    //             int idx = readyQueue.front();
    //             readyQueue.pop();

    //             if (remainingBurst[idx] <= quantum) {
    //                 currentTime += remainingBurst[idx];
    //                 remainingBurst[idx] = 0;
    //                 turnAroundTime[idx] = currentTime - arrival[idx];
    //                 waitingTime[idx] = turnAroundTime[idx] - burst[idx];
    //                 completed++;
    //             } else {
    //                 currentTime += quantum;
    //                 remainingBurst[idx] -= quantum;

    //                 for (int i = 0; i < n; i++) {
    //                     if (i != idx && arrival[i] <= currentTime && remainingBurst[i] > 0 &&
    //                         find(readyQueue.begin(), readyQueue.end(), i) == readyQueue.end()) {
    //                         readyQueue.push(i);
    //                     }
    //                 }

    //                 readyQueue.push(idx);
    //             }
    //         } else {
    //             currentTime++;
    //         }
    //     }

    //     printMetrics(arrival, burst, waitingTime, turnAroundTime);
    // }

private:
    void printMetrics(const vector<int>& arrival, const vector<int>& burst,
                      const vector<int>& waiting, const vector<int>& turnaround,
                      const vector<int>* priority = nullptr) {
        cout << "Process\tArrival\tBurst\t";
        if (priority)
            cout << "Priority\t";
        cout << "Waiting\tTurnaround\n";

        for (size_t i = 0; i < arrival.size(); i++) {
            cout << i + 1 << "\t" << arrival[i] << "\t" << burst[i] << "\t";
            if (priority)
                cout << (*priority)[i] << "\t\t";
            cout << waiting[i] << "\t" << turnaround[i] << "\n";
        }
    }
};
