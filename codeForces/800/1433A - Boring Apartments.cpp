#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        string s; cin >> s;
        if(s.size() == 1) cout << 1 + 10 * (s[0] - '0' - 1) << endl;
        else if(s.size() == 2) cout << 3 + 10 * (s[0] - '0' - 1) << endl;
        else if(s.size() == 3) cout << 6 + 10 * (s[0] - '0' - 1) << endl;
        else cout << 10 + 10 * (s[0] - '0' - 1) << endl;
    }
}