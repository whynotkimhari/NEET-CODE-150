#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int sum = 0;
        int cnt1 = 0;
        while(n--) {
            int x; cin >> x;
            sum += x;
            if(x == 1) cnt1++;
        }
        
        if(sum % 2) cout << "NO\n";
        else {
            sum /= 2;
            if(sum % 2 == 0 || (sum % 2 == 1 && cnt1 != 0)) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}