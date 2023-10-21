#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve (){
    // CODE HERE
    int t; cin >> t;
    while(t--) {
        int x; cin >> x;
        string s1, s2; cin >> s1 >> s2;
        bool flag = true;

        for(int i = 0; i < x; i++) {
            if((s1[i] == 'R' || s2[i] == 'R') && s2[i] != s1[i]) {
                flag = false;
            }
        }

        flag ? cout << "YES\n" : cout << "NO\n";
    }
}

int main () {

    solve();

    return 0;
}