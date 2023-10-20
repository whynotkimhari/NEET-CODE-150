#include <bits/stdc++.h>
using namespace std;

void solve() {
    int h, m; cin >> h >> m;
    cout << (24 - h) * 60 - m << endl;
}
int main() {
    int t; cin >> t;
    while(t--) solve();
}