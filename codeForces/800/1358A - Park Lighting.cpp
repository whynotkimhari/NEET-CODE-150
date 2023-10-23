#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve (){
    // CODE HERE
    int m, n; cin >> m >> n;
    cout << (n/2)*m + (n % 2) * (m / 2 + m % 2) << endl;
}

int main () {

    int t; cin >> t;
    while(t--) solve();

    return 0;
}