// для обхода поддерева

#include <vector>

using namespace std;

const int MAXN = 100;
int l[MAXN];
int r[MAXN];
vector<int> eul;
vector<vector<int>> g(MAXN);

void dfs(int v) {
    l[v] = eul.size();
    eul.emplace_back(v);
    for (auto u : g[v]) {

    }
    r[v] = eul.size();
    eul.emplace_back(v);
}
