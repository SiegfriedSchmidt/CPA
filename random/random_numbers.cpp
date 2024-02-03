#include <iostream>

using namespace std;

int main() {
    srand((unsigned) time(nullptr));
    cout << time(nullptr) << "\n\n";

    int cnt[10] = {};
    for (int i = 0; i < 1000000; ++i) {
        cnt[rand() % 10]++;
    }

    for (int i = 0; i < 10; ++i) {
        cout << cnt[i] << '\n';
    }

    return 0;
}