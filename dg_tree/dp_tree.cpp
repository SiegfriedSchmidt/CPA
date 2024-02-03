#include <iostream>
#include <vector>

using namespace std;

#define int long long

const int MAXN = 1e5;

vector<vector<int>> g(MAXN);

int dp[MAXN][2];

void dfs(int v, int pr = -1) {
    dp[v][0] = 1;
    dp[v][1] = 0;
    for (auto u : g[v]) {
        if (u != pr) {
            dfs(u, v);
            dp[v][0] += dp[u][1];
            dp[v][1] += max(dp[u][0], dp[u][1]);
        }
    }
}
