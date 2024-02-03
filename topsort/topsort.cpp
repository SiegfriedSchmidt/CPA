#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 1e3;

int n; // число вершин
vector<vector<int>> g(MAXN); // граф
bool used[MAXN];
vector<int> topsort;

void dfs(int v) {
    used[v] = true;
    for (auto u: g[v]) {
        if (!used[u]) {
            dfs(u);
        }
    }
    topsort.emplace_back(v);
}

void topological_sort() {
    fill(used, used + MAXN, false);
    topsort.clear();
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            dfs(i);
        }
    }
    reverse(topsort.begin(), topsort.end());
}