#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve (){
    // CODE HERE
    int a, b; cin >> a >> b;
    if(2*a > b) cout << -1 << " " << -1 << endl;
    else cout << a << " " << 2*a << endl;
}

int main () {

    int t; cin >> t;
    while(t--) solve();

    return 0;
}