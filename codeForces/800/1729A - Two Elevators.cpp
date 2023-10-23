#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve (){
    // CODE HERE
    int a, b, c; cin >> a >> b >> c;

    if(abs(a - 1) == abs(b - c) + abs(c - 1)) cout << 3 << endl;
    else if(abs(a - 1) > abs(b - c) + abs(c - 1)) cout << 2 << endl;
    else cout << 1 << endl;
}

int main () {

    int t; cin >> t;
    while(t--) solve();

    return 0;
}