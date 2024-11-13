#ifndef ALGORITHMS_GRAPHALGORITHM_H
#define ALGORITHMS_GRAPHALGORITHM_H
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>
#include <functional>
#include <utility>

using namespace std;

// Needed for using Pair on Set
template <typename T1, typename T2>
struct PairHash {
    std::size_t operator()(const std::pair<T1, T2>& p) const {
        std::size_t h1 = std::hash<T1>()(p.first);
        std::size_t h2 = std::hash<T2>()(p.second);
        return h1 ^ (h2 << 1);
    }
};

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

    // LC 841: Keys & Room: https://leetcode.com/problems/keys-and-rooms/
    static bool canVisitAllRooms(vector<vector<int>>& rooms);

    // LC 695: Largest Island or Max are of Island: https://leetcode.com/problems/max-area-of-island/
    static int maxAreaOfIsland(vector<vector<int>>& grid);

    // HackerRank: Astronaut Pairs: https://www.hackerrank.com/contests/alcoding-summer-challenge/challenges/astronaut-pairs/problem
    static void astronautPair();

    // LC 332: Reconstruct Itinerary: https://leetcode.com/problems/reconstruct-itinerary/
    static vector<string> findItinerary(vector<vector<string>>& tickets);

    // LC 684. Redundant Connection:  https://leetcode.com/problems/redundant-connection/description/
    static vector<int> findRedundantConnection(vector<vector<int>>& edges);
};


#endif
