#include <bits/stdc++.h>

using namespace std;

#define int long long
#define mp make_pair

constexpr int INF = (1ll << 62);
constexpr int MAXN = 900'202;

constexpr int MOD1 = 1e9 + 7;
constexpr int MOD2 = 1e9 + 3;
constexpr int P1 = 320;
constexpr int P2 = 410;

pair<int, int> p[MAXN + 1];

pair<int, int> getHash(const vector<pair<int, int>> &h, int l, int r) {
    int h1 = (h[r].first - (l - 1 >= 0 ? h[l - 1].first : 0) + MOD1) % MOD1 * p[MAXN - r].first % MOD1;
    int h2 = (h[r].second - (l - 1 >= 0 ? h[l - 1].second : 0) + MOD2) % MOD2 * p[MAXN - r].second % MOD2;
    return {h1, h2};
}

signed main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    string type, s;
    int n;
    cin >> type >> n >> s;


    string t = "1110111010001011110011000110000111001001011110101000100001111000111110010100100101011101110000011101";

    if (type == "send") {
        cout << t + s;
    } else {
        int n1 = s.size();
        s += s;
        p[0] = {1, 1};
        for (int i = 1; i <= MAXN; ++i) {
            p[i] = {p[i - 1].first * P1 % MOD1, p[i - 1].second * P2 % MOD2};
        }

        vector<pair<int, int>> ht(t.size());
        vector<pair<int, int>> hs(s.size());
        ht[0] = {t[0], t[0]};
        for (int i = 1; i < t.size(); ++i) {
            ht[i].first = (ht[i - 1].first + t[i] * p[i].first) % MOD1;
            ht[i].second = (ht[i - 1].second + t[i] * p[i].second) % MOD2;
        }

        hs[0] = {s[0], s[0]};
        for (int i = 1; i < s.size(); ++i) {
            hs[i].first = (hs[i - 1].first + s[i] * p[i].first) % MOD1;
            hs[i].second = (hs[i - 1].second + s[i] * p[i].second) % MOD2;
        }

        int idx = -1;
        for (int i = 0; i + t.size() < s.size(); ++i) {
            if (getHash(hs, i, i + t.size() - 1) == getHash(ht, 0, t.size() - 1)) {
                idx = i;
                break;
            }
        }

        cout << s.substr(idx + t.size(), n1 - t.size());
    }

    return 0;
}