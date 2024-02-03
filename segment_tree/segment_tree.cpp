#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define int long long

const int MAXN = 100000;
const int INF = 1e18;

array<int, MAXN * 4> tree;
array<int, MAXN * 4> upd;

void build(int ver, int tl, int tr) {
    if (tr - tl == 1) {
        upd[ver] = 1;
        tree[ver] = 1;
        return;
    }
    int mid = (tl + tr) / 2;
    build(ver * 2 + 1, tl, mid);
    build(ver * 2 + 2, mid, tr);
    tree[ver] = (tree[ver * 2 + 1] + tree[ver * 2 + 2]) % INF;
    upd[ver] = 1;
}

void push(int ver, int tl, int tr) {
    if (upd[ver] == INF) {
        return;
    }
    if (tl + 1 != tr) {
        upd[ver * 2 + 1] = upd[ver];
        upd[ver * 2 + 2] = upd[ver];
    }
    tree[ver] = upd[ver];
    upd[ver] = INF;
}

int ans(int ver, int tl, int tr, int l, int r) {
    push(ver, tl, tr);
    if (tl >= r || tr <= l) {
        return INF;
    }
    if (tl >= l && tr <= r) {
        return tree[ver];
    }
    int mid = (tl + tr) / 2;
    return min(ans(ver * 2 + 1, tl, mid, l, r), ans(ver * 2 + 2, mid, tr, l, r));
}

void update(int ver, int tl, int tr, int l, int r, int val) {
    push(ver, tl, tr);
    if (tl >= r || tr <= l) {
        return;
    }
    if (tl >= l && tr <= r) {
        upd[ver] = val;
        push(ver, tl, tr);
        return;
    }
    int mid = (tl + tr) / 2;
    update(ver * 2 + 1, tl, mid, l, r, val);
    update(ver * 2 + 2, mid, tr, l, r, val);
    tree[ver] = min(tree[ver * 2 + 1], tree[ver * 2 + 2]);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    fill(upd.begin(), upd.end(), INF);
//    fill(tree.begin(), tree.end(), INF);
//    build(0, 0, n);
    for (int i = 0; i < m; ++i) {
        int t;
        cin >> t;
        if (t == 1) {
            int l, r, val;
            cin >> l >> r >> val;
            update(0, 0, n, l, r, val);
        } else {
            int l, r;
            cin >> l >> r;
            cout << ans(0, 0, n, l, r) << '\n';
        }
    }
}
