#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve (){
    // CODE HERE
    int t; cin >> t;
    while(t--) {
        int x; cin >> x;
        string s; cin >> s;

        if(x != 5) cout << "NO\n";
        else {
            map<char,int> c;
            for(int i=0; i<x; i++) c[s[i]]++;

            if(c['T'] == 1 && c['i'] == 1 && c['m'] == 1 && c['u'] == 1 && c['r'] == 1) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}

int main () {

    solve();

    return 0;
}