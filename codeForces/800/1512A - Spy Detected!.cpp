#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> v(n);
        map<int, pair<int,int>> m;
        for(int i = 0; i < n; i++) {
            int tmp; cin >> tmp;
            if(m.find(tmp) != m.end()) m[tmp].second++;
            else m[tmp] = {i + 1, 1};
        }

        for(auto &k : m) if(k.second.second == 1) cout << k.second.first << '\n';
    }
}