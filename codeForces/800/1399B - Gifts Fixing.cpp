#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve (){
    // CODE HERE
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int m1 = INT_MAX, m2 = INT_MAX;
        ll sum = 0;
        vector<int> v1(n), v2(n);
        for(int i=0; i<n; i++) {
            cin >> v1[i];
            if(m1 > v1[i]) m1 = v1[i];
        }
        for(int i=0; i<n; i++) {
            cin >> v2[i];
            if(m2 > v2[i]) m2 = v2[i];
        }

        for(int i=0; i<n; i++) {
            sum += max(v1[i] - m1, v2[i] - m2);
        }

        cout << sum << endl;
    }
}

int main () {

    solve();

    return 0;
}