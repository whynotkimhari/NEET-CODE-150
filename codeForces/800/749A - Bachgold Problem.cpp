#include <bits/stdc++.h>
using namespace std;

void solve(int x) {
    if(x == 2) cout << 2 << " ";
    if(x == 3) cout << 3 << " ";
    if(x > 3) {
        cout << 2 << " ";
        solve(x - 2);
    }
}

int main() {
    int n; cin >> n;
    cout << n / 2 << endl;
    solve(n);
}