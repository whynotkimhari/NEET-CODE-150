#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x; cin >> n >> x;
    if(n == 1 || n == 2) cout << 1 << endl;
    else {
        int t = (n - 2) % x != 0 ? 1 : 0;
        cout << (n - 2) / x + 1 + t << endl;
    }
}

int main() {
    int t; cin >> t;
    while(t--) solve();
}