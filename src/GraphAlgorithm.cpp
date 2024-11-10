#include "../header/GraphAlgorithm.h"

int GraphAlgorithm::snakesAndLadders(vector<vector<int>> &board) {
    const int n = int(board.size());
    queue<pair<int,int>> qq;
    bool *visited = new bool[n*n+1]();
    qq.emplace(1,0); // starting node
    visited[1] = true;
    while (!qq.empty()) {
        auto pp = qq.front(); qq.pop();
        int node = pp.first;
        if (node >= n*n) {
            delete[] visited;
            return pp.second;
        }
        for(int i=1; i<=6; ++i) {
            int nbr = std::min(node+i, n*n);
            if (visited[nbr]) continue;
            visited[nbr] = true;
            int row = n - (nbr-1)/n - 1;
            int col = ((nbr-1)/n) % 2 == 0 ? (nbr-1)%n : n - (nbr-1)%n - 1;
            if (board[row][col] != -1) nbr = board[row][col];
            qq.emplace(nbr, pp.second+1);
        }
    }
    delete[] visited;
    return -1;
}
