#include <iostream>
#include <vector>

using namespace std;

#define int long long

int find_sm(int x1, int y1, int x2, int y2, vector<vector<int>> &pref) {
    return pref[x2 + 1][y2 + 1] - pref[x1][y2 + 1] - pref[x2 + 1][y1] + pref[x1][y1];
}

signed main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    freopen(R"(D:\Users\Matvei\Developer\Projects\WSL_CPP_TEST\streams\input.txt)", "r", stdin);

    int n, m;
    cin >> n >> m;

    int a[n][m];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }

    vector<vector<int>> pref(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            pref[i + 1][j + 1] = pref[i][j + 1] + pref[i + 1][j] - pref[i][j] + a[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << pref[i + 1][j + 1] << ' ';
        }
        cout << '\n';
    }

    cout << find_sm(1, 1, 2, 3, pref);

    return 0;
}

/*
4 5
1 5 6 11 8
1 7 11 9 4
4 6 1 3 2
7 5 4 2 3

 */