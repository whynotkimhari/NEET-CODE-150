#include <iostream>
using namespace std;

int main() {
    int n, m = 1; cin >>n;
    while (m <= n) {
        if (m%2 == 0) cout << "I love ";
        else cout << "I hate ";

        if (m < n) cout << "that ";
        else cout << "it ";
        ++m;
    }
}