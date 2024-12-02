#include <iostream>
#include <vector>
#include <queue>
#include <bits/stdc++.h>
#include <unordered_map>
#include "PageReplacement.h"
#include "Scheduling.h"
#include "MemoryAllocation.h"

using namespace std;

int main(){

    vector<int> pages = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
    int frameCount = 3;

    PageReplacement pageReplace;
    pageReplace.fifoPageReplacement(pages, frameCount);
    pageReplace.lruPageReplacement(pages, frameCount);

    // Memory Allocation
    vector<int> memoryBlocks = {100, 500, 200, 300, 600};
    vector<int> processSizes = {212, 417, 112, 426};

    MemoryAllocation memAlloc(memoryBlocks);

    memAlloc.firstFit(processSizes);
    memAlloc.nextFit(processSizes);
    memAlloc.bestFit(processSizes);
    memAlloc.worstFit(processSizes);

    vector<int> arrival = {0, 2, 4, 6};
    vector<int> burst = {8, 4, 2, 1};
    vector<int> priority = {3, 1, 4, 2};
    int quantum = 2;

    Scheduling sched;
    sched.fcfs(arrival, burst);
    sched.sjf(arrival, burst);
    sched.priorityScheduling(arrival, burst, priority);
    // sched.roundRobin(arrival, burst, quantum);


    return 0;
}