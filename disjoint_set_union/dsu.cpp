#include <iostream>
#include <set>
#include <map>
#include <stack>
#include <string>
#include <chrono>

using namespace std;

#define mp make_pair
#define int long long

const int INF = 1e9 + 7;

int p[300000];
int sz[300000];
pair<int, int> mnmx[300000];

int get(int x) {
    if (p[x] == x) {
        return x;
    }
    return p[x] = get(p[x]);
//    return p[x] = (p[x] == x ? x : get(p[x]));
}

void unionn(int x, int y) {
    int a = get(x);
    int b = get(y);
    if (a == b) {
        return;
    }
    if (sz[b] > sz[a]) {
        swap(a, b);
    }

    p[b] = a;
    sz[a] += sz[b];

    mnmx[a] = {min(mnmx[a].first, mnmx[b].first), max(mnmx[a].second, mnmx[b].second)};
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        p[i] = i;
        sz[i] = 1;
        mnmx[i] = {i, i};
    }

    for (int i = 0; i < m; ++i) {
        string oper;
        cin >> oper;

        if (oper == "union") {
            int x, y;
            cin >> x >> y;
            --x;
            --y;
            unionn(x, y);
        } else {
            int x;
            cin >> x;
            --x;
            cout << mnmx[get(x)].first + 1 << ' ' << mnmx[get(x)].second + 1 << ' ' << sz[get(x)] << '\n';
        }
    }

    return 0;
}
