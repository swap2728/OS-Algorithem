#include <iostream>
#include <vector>
#include <queue>
#include <bits/stdc++.h>
#include <unordered_map>
// #include "OS.h"

using namespace std;

class PageReplacement  {
public:
    // FIFO Page Replacement Algorithm
    void fifoPageReplacement(vector<int> pages, int frameCount) {
        cout << "FIFO Page Replacement:" << endl;
        queue<int> frames;
        unordered_map<int, bool> inFrames;
        int pageFaults = 0;

        for (int page : pages) {
            if (!inFrames[page]) {
                pageFaults++;
                if (frames.size() == frameCount) {
                    int removedPage = frames.front();
                    frames.pop();
                    inFrames[removedPage] = false;
                }
                frames.push(page);
                inFrames[page] = true;
            }
            displayFrames(frames);
        }
        cout << "Total Page Faults: " << pageFaults << endl;
    }

    // LRU Page Replacement Algorithm
    void lruPageReplacement(vector<int> pages, int frameCount) {
        cout << "\nLRU Page Replacement:" << endl;
        unordered_map<int, int> lastUsed;
        vector<int> frames;
        int pageFaults = 0, time = 0;

        for (int page : pages) {
            time++;
            auto it = find(frames.begin(), frames.end(), page);
            if (it == frames.end()) {
                pageFaults++;
                if (frames.size() == frameCount) {
                    int lruPage = *min_element(frames.begin(), frames.end(),
                                               [&](int a, int b) {
                                                   return lastUsed[a] < lastUsed[b];
                                               });
                    frames.erase(find(frames.begin(), frames.end(), lruPage));
                }
                frames.push_back(page);
            }
            lastUsed[page] = time;
            displayFrames(frames);
        }
        cout << "Total Page Faults: " << pageFaults << endl;
    }

private:
    void displayFrames(const queue<int>& frames) {
        queue<int> temp = frames;
        cout << "Frames: ";
        while (!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << endl;
    }

    void displayFrames(const vector<int>& frames) {
        cout << "Frames: ";
        for (int frame : frames) {
            cout << frame << " ";
        }
        cout << endl;
    }
};

