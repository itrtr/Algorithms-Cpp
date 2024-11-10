#include <iostream>
#include "header/GraphAlgorithm.h"
using namespace std;

int main() {
    GraphAlgorithm g;
    vector<vector<int>> b {{-1,-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1,-1},{-1,35,-1,-1,13,-1},{-1,-1,-1,-1,-1,-1},{-1,15,-1,-1,-1,-1}};
    cout << g.snakesAndLadders(b) << endl;
    return 0;
}

