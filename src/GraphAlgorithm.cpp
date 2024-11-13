#include "../header/GraphAlgorithm.h"

bool findRedundantConnectionHelper(int node, vector<vector<int>>& graph, unordered_set<int>& visited, int parent) {
    for(const auto& nbr : graph[node]) {
        if (nbr == parent) continue;
        if (visited.contains(nbr)) return true;
        visited.insert(nbr);
        if (!findRedundantConnectionHelper(nbr, graph, visited, node)) {
            visited.erase(nbr);
        }
    }
    return false;
}
vector<int> GraphAlgorithm::findRedundantConnection(vector<vector<int>>& edges) {
    vector<vector<int>> graph(edges.size() + 1); // 1-based indexing
    for(const auto& edge: edges) {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }
    unordered_set<int> visited_ans;

    for(int node=1; node<=edges.size(); ++node) {
        unordered_set<int> visited;
        findRedundantConnectionHelper(node, graph, visited, node);
        if (visited_ans.empty() or visited.size() < visited_ans.size()) {
            visited_ans = visited;
        }
    }
    for(int i : visited_ans) cout << i << " ";
    for(int i=edges.size()-1; i>=0; --i) {
        if (visited_ans.contains(edges[i][0]) and visited_ans.contains(edges[i][1])) {
            return {edges[i][0], edges[i][1]};
        }
    }
    return {};
}

bool findItineraryHelper(const string& src, unordered_map<string, map<string, int>>& gh, vector<string>& ans, const int N) {
    if (ans.size() == N) return true;
    for(auto& row : gh[src]) {
        if (row.second > 0) { // still have a valid ticket
            row.second -= 1;
            ans.emplace_back(row.first);
            if (findItineraryHelper(row.first, gh, ans, N)) return true;
            row.second += 1;
            ans.pop_back();
        }
    }
    return false;
}

vector<string> GraphAlgorithm::findItinerary(vector<vector<string>>& tickets) {
    const int N = tickets.size();
    unordered_map<string, map<string, int>> gh;
    for(const auto& ticket: tickets) {
        // directed
        auto& row = gh[ticket[0]];
        row[ticket[1]]++; // same to-fro ticket can be multiple
    }
    vector<string> ans;
    ans.emplace_back("JFK");
    findItineraryHelper("JFK", gh, ans, N+1);
    return ans;
}

int findConnectedComponentsSize(int src, vector<bool>& seen, vector<vector<int>>& gh) {
    seen[src] = true;
    int sz = 1;
    for(int conn : gh[src]) {
        if (!seen[conn]) {
            sz += findConnectedComponentsSize(conn, seen, gh);
        }
    }
    return sz;
}
// Submission: https://www.hackerrank.com/contests/alcoding-summer-challenge/challenges/astronaut-pairs/submissions/code/1385233203
void GraphAlgorithm::astronautPair() {
    int n, p;
    vector<vector<int>> gh(n);
    cin >> n >> p;
    int x, y;
    for(int i=0;i<p;++i) {
        cin >> x >> y;
        gh[x].push_back(y);
        gh[y].push_back(x);
    }

    vector<bool> seen(n, false);
    vector<int> conns; // contains elements which repr the size of each connected components
    for(int node=0; node<n; ++node) {
        if (!seen[node]) { // means it can represent a connected component of any size
            conns.push_back(findConnectedComponentsSize(node, seen, gh));
        }
    }

    int ans = 0;
    for(int i=0; i<conns.size(); ++i) {
        for(int j=i+1; j<conns.size(); ++j) {
            ans += conns[i] * conns[j];
        }
    }
    printf("%d", ans);
}

int maxAreaOfIslandHelper(int x, int y, vector<vector<int>>& grid) {
    if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] != 1) {
        return 0;
    }
    int ans = 1;
    grid[x][y] = -1; // or 0 whatever just not 1
    static int dx[] = {0, 0, 1, -1};
    static int dy[] = {1, -1, 0, 0};
    for(int i=0; i<4; ++i) {
        int xx = x + dx[i];
        int yy = y + dy[i];
        ans += maxAreaOfIslandHelper(xx, yy, grid);
    }
    return ans;
}
int GraphAlgorithm::maxAreaOfIsland(vector<vector<int>>& grid) {
    int ans = 0;
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[0].size(); ++j) {
            if (grid[i][j] == 1) {
                ans = std::max(ans, maxAreaOfIslandHelper(i,j,grid));
            }
        }
    }
    return ans;
}

// We can also do DFS: https://leetcode.com/problems/keys-and-rooms/submissions/862430596/
bool GraphAlgorithm::canVisitAllRooms(vector<vector<int>>& rooms) {
    const int N = (int)rooms.size();
    vector<bool> visited(N, false);
    queue<int> qq;
    qq.push(0);
    visited[0] = true;

    while(not qq.empty()) {
        int node = qq.front(); qq.pop();
        for(int nbr : rooms[node]) {
            if (not visited[nbr]) {
                visited[nbr] = true;
                qq.push(nbr);
            }
        }
    }
    return !std::any_of(visited.begin(), visited.end(), [](bool val) {return !val;});
}

void GraphAlgorithm::validBfs() {
    int n;
    cin >> n;
    vector<vector<int>> gg(n+1);
    int a, b;
    for(int i=0;i<n-1;++i) {
        cin >> a >> b;
        gg[a].push_back(b);
        gg[b].push_back(a);
    }
    vector<int> seq(n);
    vector<int> index(n+1);
    for(int i=0;i<n;++i) {
        cin >> seq[i];
        index[seq[i]] = i;
    }
    for(auto& row : gg)
        sort(begin(row), end(row), [&index](int a, int b) {return index[a] < index[b];});

    vector<int> ans(n);
    int idx = 0;
    queue<int> qq;
    qq.push(1);
    vector<bool> visited(n+1, false);
    visited[1] = true;
    while(not qq.empty()) {
        int node = qq.front(); qq.pop();
        ans[idx++] = node;
        for(int nbr : gg[node]) {
            if(!visited[nbr]) {
                visited[nbr] = true;
                qq.push(nbr);
            }
        }
    }
    printf("%s", (seq==ans) ? "Yes" : "No");
}

int GraphAlgorithm::ladderLength(const string& beginWord, const string& endWord, vector<string> &wordList) {
    unordered_set<string> words(wordList.begin(), wordList.end());
    if (!words.contains(endWord)) return 0;
    queue<pair<string,int>> qq;
    qq.emplace(beginWord, 1);
    unordered_set<string> visited;
    visited.emplace(beginWord);
    int ans = INT_MAX;
    while (not qq.empty()) {
        const auto pp = qq.front(); qq.pop();
        if (pp.first == endWord) {
            return pp.second; // Also works!
            //ans = min(ans, pp.second); // we could have returned the first time we find endWord (greedy) but we may have separate path with less hops
        }
        string word = pp.first;
        for(char & j : word) {
            char cc = j;
            for(int i=0; i<26; ++i) {
                if (cc != ('a'+i)) {
                    j = (char)('a'+i);
                    if (words.contains(word) and !visited.contains(word)) {
                        visited.emplace(word);
                        qq.emplace(word, pp.second+1);
                    }
                }
            }
            j = cc;
        }
    }
    return ans == INT_MAX ? 0 : ans;
}

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