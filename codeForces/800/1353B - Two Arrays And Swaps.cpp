#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        int sum = 0;
        vector<int> a(n), b(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
        }
        for(int i = 0; i < n; i++) cin >> b[i];

        sort(a.begin(), a.end(), greater<int>());
        sort(b.begin(), b.end());

        vector<int> z;

        int c = k;

        while(c--) {
            sum -= a.back();
            z.push_back(a.back());
            a.pop_back();
            z.push_back(b.back());
            b.pop_back();
        }
        sort(z.begin(), z.end());

        while(k--) {
            sum += z.back();
            a.push_back(z.back());
            z.pop_back();
        }

        cout << sum << endl;
    }
}