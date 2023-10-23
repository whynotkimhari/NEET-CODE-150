#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve (){
    // CODE HERE
    int n; cin >> n;
    bool allOdd = true, allEven = true;
    for(int i=0; i<n; i++) {
        int x; cin >> x;
        if(allOdd) allOdd = x % 2 == 1;
        if(allEven) allEven = x % 2 == 0;
    }

    if(allOdd) n % 2 ? cout << "YES\n" : cout << "NO\n";
    else if(allEven) cout << "NO\n";
    else cout << "YES\n";
}

int main () {

    int t; cin >> t;
    while(t--) solve();

    return 0;
}