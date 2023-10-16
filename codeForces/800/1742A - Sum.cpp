#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, a, b, c; cin >> t;
    while(t--) {
        cin >> a >> b >> c;
        if(a == b + c || b == a + c || c == a + b) cout << "YES\n";
        else cout << "NO\n";
    }
}