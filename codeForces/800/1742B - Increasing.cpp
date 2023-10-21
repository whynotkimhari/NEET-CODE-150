#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve (){
    // CODE HERE
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> v(n);
        for(int i=0; i<n; i++) cin >> v[i];
        sort(v.begin(), v.end());

        bool flag = true;

        for(int i=0; i<n - 1; i++) {
            if(v[i] == v[i+1]) flag = false;
        }

        flag ? cout << "YES\n" : cout << "NO\n";
    }
}

int main () {

    solve();

    return 0;
}