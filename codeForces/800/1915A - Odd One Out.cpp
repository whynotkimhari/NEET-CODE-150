#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O2")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#define NDEBUG
#pragma STDC FENV_ACCESS ON
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC diagnostic pop
#pragma GCC optimize("Ofast")
#pragma inline
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic warning "-Wall"
#define ll long long

void solve () {
    // CODE HERE
    int x, y, z;
    cin >> x >> y >> z;

    if (x == y) cout << z << endl;
    else if(x == z) cout << y << endl;
    else cout << x << endl;
}

int main () {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) solve();

    return 0;
}