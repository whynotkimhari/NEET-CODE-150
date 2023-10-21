#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve (){
    // CODE HERE
    int t; cin >> t;
    while(t--) {
        string base = "codeforces";
        string s; cin >> s;
        int cnt = 0;
        for(int i=0; i < 10; i++) {
            if(s[i] != base[i]) cnt++;
        }
        cout << cnt << endl;
    }
}

int main () {

    solve();

    return 0;
}