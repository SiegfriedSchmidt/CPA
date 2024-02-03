#include <iostream>
#include <set>

int main() {
    std::set<int> set1{1, 2, 3};
    std::cout << set1.contains(2) << '\n';
    return 0;
}