#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
// #include "OS.h"

using namespace std;

class MemoryAllocation  {
private:
    vector<in   t> memoryBlocks; // Available memory blocks
public:
    MemoryAllocation(vector<int> blocks) : memoryBlocks(blocks) {}

    // First Fit Algorithm
    void firstFit(vector<int> processSizes) {
        cout << "First Fit Allocation:" << endl;
        for (int process : processSizes) {
            bool allocated = false;
            for (int &block : memoryBlocks) {
                if (block >= process) {
                    cout << "Process of size " << process << " allocated in block of size " << block << endl;
                    block -= process;
                    allocated = true;
                    break;
                }
            }
            if (!allocated)
                cout << "Process of size " << process << " could not be allocated." << endl;
        }
    }

    // Next Fit Algorithm
    void nextFit(vector<int> processSizes) {
        cout << "\nNext Fit Allocation:" << endl;
        int lastPos = 0; // Track last allocated position
        for (int process : processSizes) {
            bool allocated = false;
            for (size_t i = 0; i < memoryBlocks.size(); i++) {
                int idx = (lastPos + i) % memoryBlocks.size(); // Circular search
                if (memoryBlocks[idx] >= process) {
                    cout << "Process of size " << process << " allocated in block of size " << memoryBlocks[idx] << endl;
                    memoryBlocks[idx] -= process;
                    lastPos = idx; // Update last position
                    allocated = true;
                    break;
                }
            }
            if (!allocated)
                cout << "Process of size " << process << " could not be allocated." << endl;
        }
    }

    // Best Fit Algorithm
    void bestFit(vector<int> processSizes) {
        cout << "\nBest Fit Allocation:" << endl;
        for (int process : processSizes) {
            int bestIdx = -1;
            for (size_t i = 0; i < memoryBlocks.size(); i++) {
                if (memoryBlocks[i] >= process &&
                    (bestIdx == -1 || memoryBlocks[i] < memoryBlocks[bestIdx])) {
                    bestIdx = i;
                }
            }
            if (bestIdx != -1) {
                cout << "Process of size " << process << " allocated in block of size " << memoryBlocks[bestIdx] << endl;
                memoryBlocks[bestIdx] -= process;
            } else {
                cout << "Process of size " << process << " could not be allocated." << endl;
            }
        }
    }

    // Worst Fit Algorithm
    void worstFit(vector<int> processSizes) {
        cout << "\nWorst Fit Allocation:" << endl;
        for (int process : processSizes) {
            int worstIdx = -1;
            for (size_t i = 0; i < memoryBlocks.size(); i++) {
                if (memoryBlocks[i] >= process &&
                    (worstIdx == -1 || memoryBlocks[i] > memoryBlocks[worstIdx])) {
                    worstIdx = i;
                }
            }
            if (worstIdx != -1) {
                cout << "Process of size " << process << " allocated in block of size " << memoryBlocks[worstIdx] << endl;
                memoryBlocks[worstIdx] -= process;
            } else {
                cout << "Process of size " << process << " could not be allocated." << endl;
            }
        }
    }
};

