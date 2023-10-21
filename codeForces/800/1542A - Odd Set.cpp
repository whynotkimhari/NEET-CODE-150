#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve (){
    // CODE HERE
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int e = 0, o = 0;
        for(int i=0; i<2*n; i++) {
            int x; cin >> x;
            x % 2 ? o++ : e++;
        }
        
        e != o ? cout << "No\n" : cout << "Yes\n";
    }
}

int main () {

    solve();

    return 0;
}