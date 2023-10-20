#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve (){
    // CODE HERE
    int t; cin >> t;
    while(t--) {
        vector<int> v(4);
        cin >> v[0] >> v[1] >> v[2] >> v[3];
        
        int m = (v[0] + v[1] + v[2] + v[3]);
        bool printed = false;

        for(int i = 0; i < 3; i++) {
            if(v[i] > m / 3) {
                cout << "NO\n";
                printed = true;
                break;
            }
        }
        if(printed) continue;

        if(m % 3) cout << "NO\n";
        else cout << "YES\n";
    }
}

int main () {

    solve();

    return 0;
}