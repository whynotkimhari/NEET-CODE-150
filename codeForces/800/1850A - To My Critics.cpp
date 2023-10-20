#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve (){
    // CODE HERE
    int t; cin >> t;
    while(t--) {
        int a, b, c; cin >> a >> b >> c;
        if(a + b >= 10 || a + c >= 10 || b + c >= 10) cout << "YES\n";
        else cout << "NO\n";
    }
}

int main () {

    solve();

    return 0;
}