#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    string s;
    while(n--) {
        cin >> s;
        int fs = (s[0] - '0') + (s[1] - '0') + (s[2] - '0');
        int bs = (s[s.size() - 3] - '0') + (s[s.size() - 2] - '0') + (s[s.size() - 1] - '0');
        if(fs == bs) cout << "YES\n";
        else cout << "NO\n";
    }
}