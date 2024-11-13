#include "header/GraphAlgorithm.h"
using namespace std;

int main() {
    vector<vector<int>> edges {{2,7},{7,8},{3,6},{2,5},{6,8},{4,8},{2,8},{1,8},{7,10},{3,9}};
    GraphAlgorithm::findRedundantConnection(edges);
}

