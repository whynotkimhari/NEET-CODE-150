#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve (){
    // CODE HERE
    int t; cin >> t;
    while(t--) {
        int w, h, n; cin >> w >> h >> n;
        int cnt = 1, s = w * h;
        
        while(w % 2 == 0) {
            cnt *= 2;
            w /= 2;
        }

        while(h % 2 == 0) {
            cnt *= 2;
            h /= 2;
        }
       
        cnt >= n ? cout << "YES\n" : cout << "NO\n";
    }
}

int main () {

    solve();

    return 0;
}