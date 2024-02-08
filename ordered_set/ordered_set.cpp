#include <iostream>
#include <random>
#include <chrono>

#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less_equal<>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int main() {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

    ordered_set st;
    for (int i = 0; i < 10; ++i) {
        st.insert(rng() % 10);
    }
    for (auto i: st) {
        cout << i << ' ';
    }
    cout << '\n';
    cout << st.order_of_key(5) << '\n';
    cout << *st.find_by_order(8);
}