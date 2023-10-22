#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve (){
    // CODE HERE
    int t; cin >> t;
    while(t--) {
        int x; cin >> x;
        int max = -1;
        string s; cin >> s;

        for(int i = 0; i < x; i++) {
            max = max > s[i] - 'a' ? max : s[i] - 'a';
        }
        cout << max + 1 << endl;
    }
}

int main () {

    solve();

    return 0;
}