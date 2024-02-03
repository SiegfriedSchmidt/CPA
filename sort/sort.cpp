#include <iostream>
#include <numeric>

using namespace std;

#define int long long

signed main() {
    pair<int, int> a[10];
    sort(a, a + 10, [](pair<int, int> &lhs, pair<int, int> &rhs) {
        return lhs.first > rhs.first;
    });
}
