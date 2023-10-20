#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve (){
    // CODE HERE
    char init = 'a';
    int sum = 0;
    string s; cin >> s;

    for(int i=0; i<s.length();i++) {
        sum += min(abs(init - s[i]), 26 - abs(init - s[i]));
        init = s[i];
    }
    cout << sum << endl;
}

int main () {

    solve();

    return 0;
}