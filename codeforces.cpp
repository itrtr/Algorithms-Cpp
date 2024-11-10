// https://codeforces.com/problemset/submission/1037/290982023
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
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
    return 0;
}