#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    int x, y, n;
    while(t--) {
        cin >> x >> y >> n;
        
        if(n - n % x + y <= n) cout << n - n % x + y << endl;
        else cout << n - n % x - (x - y) << endl;
    }
}