#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        string s; cin >> s;

        map<char,int> m;
        bool pass = true;
        for(int i = 0; i < s.size(); i++) {
            if(!m[s[i]]) m[s[i]] = i + 1;
            else {
                if(m[s[i]] != i) {
                    pass = false;
                    cout << "NO\n";
                    break;;
                }
                else m[s[i]] = i + 1;
            }
        }

        if(pass) cout << "YES\n";
    }
}