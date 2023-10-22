#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve (){
    // CODE HERE
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int cnt = 0;
        vector<int> v(n);
        for(int i = 0; i < n; i++) cin >> v[i];

        for(int i = 1; i < n; i++) {
            if(v[i - 1] > v[i]) {
                // cout << "|" << v[i - 1] << " " << v[i] << " ";
                // cout << log2(v[i - 1] / (v[i] * 1.0)) << " ";
                // cout << (int)ceil(log2(v[i - 1] / (v[i] * 1.0))) << endl;
                cnt = cnt + (int)ceil(log2(v[i - 1] / (v[i] * 1.0)));
                v[i] *= (int)pow(2,(int)ceil(log2(v[i - 1] / (v[i] * 1.0))));
            }
            
        }
        cout << cnt << endl;
    }
}

int main () {

    solve();

    return 0;
}