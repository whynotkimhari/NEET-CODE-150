#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve (){
    // CODE HERE
    int t; cin >> t;
    while(t--) {
        int n, m = INT_MAX, sum = 0; cin >> n;
        vector<int> v(n);
        for(int i=0; i<n; i++) {
            cin >> v[i];
            sum += v[i];
            m = m < v[i] ? m : v[i];
        }
        cout << sum - n * m << endl;
    }
}

int main () {

    solve();

    return 0;
}