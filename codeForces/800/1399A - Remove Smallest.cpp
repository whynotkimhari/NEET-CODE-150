#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> v(n);
        int i = 0;
        while(i < n) cin >> v[i++];
        sort(v.begin(), v.end());

        int id = 0, size = n;
        bool p = true;
        while(id < n - 1) {
            if(v[id + 1] - v[id] <= 1) {
                size--;
                id++;
            }
            else {
                cout << "NO\n";
                p = false;
                break;;
            }
        }
        if(p)
            cout << "YES\n";
    }
}