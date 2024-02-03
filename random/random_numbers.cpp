#include <iostream>
#include <random>
#include <chrono>

using namespace std;

int main() {
//    mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

    for (int i = 0; i < 10; ++i) {
        cout << rng() << '\n';
    }
    cout << '\n';

    int cnt[10] = {};
    for (int i = 0; i < 1000000; ++i) {
        cnt[rng() % 10]++;
    }

    for (int a: cnt) {
        cout << a << '\n';
    }

    return 0;
}