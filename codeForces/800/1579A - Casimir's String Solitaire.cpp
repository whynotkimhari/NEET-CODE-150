#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve (){
    // CODE HERE
    int cntA = 0, cntB = 0, cntC = 0;
    string s; cin >> s;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == 'A') cntA++;
        else if(s[i] == 'B') cntB++;
        else cntC++;
    }

    cntB == cntA + cntC ? cout << "YES\n" : cout << "NO\n";
}

int main () {

    int t; cin >> t;
    while(t--) solve();

    return 0;
}