#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        string s; cin >> s;
        if(s.size() % 2) cout << "NO\n";
        else {
            int n = s.size();
            if(s.substr(0, n / 2) == s.substr(n / 2, n)) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}