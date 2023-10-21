#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve (){
    // CODE HERE
    int t; cin >> t;
    while(t--) {
        int x; cin >> x;
        string s; cin >> s;
        int a = 0, b = 0;
        bool flag = false;
        for(int i = 0; i < x; i++) {
            if(s[i] == 'U') b++;
            else if(s[i] == 'D') b--;
            else if(s[i] == 'R') a++;
            else a--;

            if(a == b && a == 1) flag = true;
        }

        flag ? cout << "YES\n" : cout << "NO\n";
    }
}

int main () {

    solve();

    return 0;
}