/*
 * //https://cses.fi/problemset/result/11123534/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void messageRoute() {
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

int main() {
    messageRoute();
}
 */