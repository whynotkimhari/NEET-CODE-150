#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve (){
    // CODE HERE
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        cout << n << " ";
        for(int i = 1; i < n; i++) {
            cout << i << " ";
        }
        cout << endl;
    }
}

int main () {

    solve();

    return 0;
}