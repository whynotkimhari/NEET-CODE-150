#include <bits/stdc++.h>
using namespace std;

int max(int a, int b) {
    return a > b ? a : b;
}

int min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    int t; cin >> t;
    while(t--) {
        int a, b; cin >> a >> b;
        cout << min(max(2 * a, b) * max(2 * a, b), max(a, 2 * b) * max(a, 2 * b)) << endl;
    }
}