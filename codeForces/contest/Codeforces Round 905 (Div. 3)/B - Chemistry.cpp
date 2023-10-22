#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve (){
    // CODE HERE
    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        string s; cin >> s;

        map<int, int> m;
        for(int i = 0; i < n; i++) {
            m[s[i]]++;
        }
        
        for(auto &key: m) {
            if(!k) break;
            if(key.second % 2) {
                key.second--;
                k--;
            }
        }
        int cnt = 0;
        for(auto &key : m) {
            if(key.second % 2) cnt++;
        }

        cnt <= 1 ? cout << "YES\n" : cout << "NO\n";
    }
}

int main () {

    solve();

    return 0;
}