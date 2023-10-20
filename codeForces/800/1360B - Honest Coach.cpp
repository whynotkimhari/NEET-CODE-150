#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());

    int wd = INT_MAX;
    for(int i = 0; i < n - 1; i++) {
        int x = abs(v[i + 1] - v[i]);
        wd = (wd > x) ? x : wd; 
    }
    cout << wd << endl;
}

int main() {
    int t; cin >> t;
    while(t--) {
        solve();
    }
}