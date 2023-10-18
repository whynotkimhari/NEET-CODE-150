#include <bits/stdc++.h>
using namespace std;

int main() {
    map<char, int> m;
    cin >> m['1'] >> m['2'] >> m['3'] >> m['4'];
    string s; cin >> s;
    int ans = 0;
    for(int i = 0; i < s.size(); i++) ans += m[s[i]];
    cout << ans;
}