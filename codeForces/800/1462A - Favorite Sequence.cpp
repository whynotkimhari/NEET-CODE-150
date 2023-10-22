#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve (){
    // CODE HERE
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> v(n);
        for(int i = 0; i < n; i++) cin >> v[i];

        int l = 0, r = n - 1;
        while(l < r) {
            cout << v[l] << " " << v[r] << " ";
            l++; r--;
        }
        
        l == r ? cout << v[l] << endl : cout << endl;
    }
}

int main () {

    solve();

    return 0;
}