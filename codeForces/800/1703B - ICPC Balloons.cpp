#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve (){
    // CODE HERE
    int t; cin >> t;
    while(t--) {
        int x, b = 0; cin >> x;
        set<char> set;
        string s; cin >> s;
        for(int i=0; i<x; i++) {
            if(set.find(s[i]) != set.end()) b++;
            else {
                b += 2;
                set.insert(s[i]);
            }
        }
        cout << b << endl;
    }
}

int main () {

    solve();

    return 0;
}