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

//https://cses.fi/problemset/result/11123534/
void GraphAlgorithm::messageRoute() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> conns(n+1); // 1-based indexing
    int a, b;
    for(int i = 0; i<m; ++i) {
        cin >> a >> b;
        conns[a].push_back(b);
        conns[b].push_back(a);
    }
    vector<int> par(n+1, -1); // 1-based indexing
    vector<bool> visited(n+1, false); // 1-based indexing
    queue<pair<int,int>> qq;
    qq.emplace(1, 1);
    visited[1] = true;
    par[1] = 1; // parent of itself since starting from here
    while(not qq.empty()) {
        const auto& pp = qq.front(); qq.pop();
        if (pp.first == n) {
            printf("%d\n",pp.second);
            vector<int> path;
            int nn = n;
            while(par[nn] != nn) {
                path.push_back(nn);
                nn = par[nn];
            }
            printf("1 ");
            for(int i=path.size()-1; i>=0; --i) printf("%d ", path[i]);
            printf("\n");
            return;
        }
        for(const auto& nbr: conns[pp.first]) {
            if (!visited[nbr]) {
                visited[nbr] = true;
                par[nbr] = pp.first;
                qq.emplace(nbr, pp.second+1);
            }
        }
    }
    printf("IMPOSSIBLE");
}