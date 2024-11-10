#ifndef ALGORITHMS_GRAPHALGORITHM_H
#define ALGORITHMS_GRAPHALGORITHM_H
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;
class GraphAlgorithm {
public:
    // Breadth First Search (BFS)
    // LC 909 Snakes and Ladder: https://leetcode.com/problems/snakes-and-ladders/description/
    static int snakesAndLadders(vector<vector<int>>& board);

    // CSES: https://cses.fi/problemset/task/1667/
    static void messageRoute();

    // LC 127: Word Ladder: https://leetcode.com/problems/word-ladder/
    static int ladderLength(const string& beginWord, const string& endWord, vector<string>& wordList);

    // Codeforces 1037D: Valid Bfs
    static void validBfs();

};


#endif
