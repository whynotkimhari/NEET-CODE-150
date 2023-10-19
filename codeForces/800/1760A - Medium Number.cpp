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
    int a, b, c, M, m; 
    while(t--) {
        cin >> a >> b >> c;
        M = max(a, max(b, c));
        m = min(a, min(b, c));

        cout << (a + b + c) - M - m << endl;
    }
}