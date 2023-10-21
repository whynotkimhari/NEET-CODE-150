#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve (){
    // CODE HERE
    int t; cin >> t;
    while(t--) {
        int a, b; cin >> a >> b;
        
        if(a == b) cout << 0 << endl;
        else if(a < b) (b - a) % 2 ? cout << 1 << endl : cout << 2 << endl;
        else (a - b) % 2 ? cout << 2 << endl : cout << 1 << endl;;
    }
}

int main () {

    solve();

    return 0;
}