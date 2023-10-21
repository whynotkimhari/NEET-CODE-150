#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve (){
    // CODE HERE
    int t; cin >> t;
    while(t--) {
        string s; cin >> s;
        cout << (s[0] - '0' + s[2] - '0') << endl;
    }
}

int main () {

    solve();

    return 0;
}