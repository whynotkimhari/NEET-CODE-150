#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve (){
    // CODE HERE
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;

        int res = 0;
        
        for (ll pw = 1; pw <= n; pw = pw * 10 + 1) {
            for (int d = 1; d <= 9;  d++) {
                if (pw * d <= n) {
                    res++;
                }
            }
        }

        cout << res << endl;
    }
}

int main () {

    solve();

    return 0;
}