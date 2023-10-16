#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int a, b; cin >> a >> b;

        int k = abs(b - a);
        if(!k) cout << "0\n";
        else {
            int cnt = k / 10;
            
            (k % 10) ? cnt++ : 1;

            cout << cnt << '\n';
        }
    }
}