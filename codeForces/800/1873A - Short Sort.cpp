#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve (){
    // CODE HERE
    string s; cin >> s;
    
    int wrong = 0;
    if(s[0] != 'a') wrong++;
    if(s[1] != 'b') wrong++;
    if(s[2] != 'c') wrong++;

    wrong > 2 ? cout << "NO\n" : cout << "YES\n";
}

int main () {

    int t; cin >> t;
    while(t--) solve();

    return 0;
}