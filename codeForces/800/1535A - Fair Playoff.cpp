#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a, b, c, d; cin >> a >> b >> c >> d;

    vector<int> v = {a, b, c, d};
    sort(v.begin(), v.end());
    ((a == v[2] || b == v[2] || b == v[3] || a == v[3]) && (c == v[3] || d == v[3] || c == v[2] || d == v[2])) ? cout << "YES\n" : cout << "NO\n";
}
int main() {
    int t; cin >> t;
    while(t--) solve();
}