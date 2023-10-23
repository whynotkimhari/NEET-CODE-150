#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve (){
    // CODE HERE
    int n; cin >> n;
    if(n % 2) cout << -1;
    else {
        vector<int> v(n);
        for(int i = 0; i < n; i++) v[i] = i + 1;
        for(int i = 0; i < n - 1; i += 2) {
            int x = v[i];
            v[i] = v[i + 1];
            v[i + 1] = x;
        }
        for(int i = 0; i < n; i++) cout << v[i] << " ";
    }
}

int main () {

    int t = 1;
    while(t--) solve();

    return 0;
}