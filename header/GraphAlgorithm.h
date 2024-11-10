#ifndef ALGORITHMS_GRAPHALGORITHM_H
#define ALGORITHMS_GRAPHALGORITHM_H
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
class GraphAlgorithm {
public:
    // Breadth First Search (BFS)
    // 1. LC 909 Snakes and Ladder: https://leetcode.com/problems/snakes-and-ladders/description/
    static int snakesAndLadders(vector<vector<int>>& board);

    // CSES: https://cses.fi/problemset/task/1667/
    static void messageRoute();
};


#endif
