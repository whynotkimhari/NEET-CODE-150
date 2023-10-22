#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve (){
    // CODE HERE
    int t; cin >> t;
    while(t--) {
        string s; cin >> s;
        int init = 1;

        int sum = 0;

        for(int i = 0; i < 4; i++) {
            if(s[i] - '0' == 0) sum = sum + abs(10 - init + 1);
            else sum = sum + abs(s[i] - '0' - init) + 1;

            init = s[i] - '0' ? s[i] - '0' : 10;
        }
        cout << sum << endl;
    }
}

int main () {

    solve();

    return 0;
}