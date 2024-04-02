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
    int n; cin >> n;
    int min = INT_MAX;
    int product = 1;
    int cntZero = 0;

    while(n--) {
        int x; cin >> x;
        x > 0 && (product *= x);
        !x && cntZero++;
        if(x < min) min = x;
    }

    if(cntZero <= 1) {
        if (min)
            cout << (product / min) + product << endl;
        else
            cout << product << endl;
    }
    else cout << 0 << endl;
}

int main () {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) solve();

    return 0;
}