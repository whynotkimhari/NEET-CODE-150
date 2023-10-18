#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int n, en, on, x, svt = 0, e = 0, o = 0; 
        cin >> n;
        
        (n % 2) ? en = n / 2 + 1 : en = n / 2;
        on = n - en;

        for(int i = 0; i < n; i++) {
            cin >> x;
            if(x % 2 != i % 2) svt++;
            
            (x % 2) ? o++ : e++;
        }

        (e != en || o != on) ? cout << "-1\n" : cout << svt/2 << '\n';
    }
}