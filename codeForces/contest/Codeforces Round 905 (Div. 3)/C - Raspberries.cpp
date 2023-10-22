#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve (){
    // CODE HERE
    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        vector<int> v(n);
        int e = 0, o = 0, p = 1;
        for(int i = 0; i < n; i++) {
            cin >> v[i];
            p *= v[i];
            if(v[i] % 2) o++;
            else e++;
        }

        sort(v.begin(), v.end());

        if(k == 2) {
            if(e >= 1) cout << 0 << endl;
            else cout << 1 << endl;
        }
        else if(k == 3) {
            int m1 = INT_MAX, m2 = INT_MAX, m3 = INT_MAX, m4 = INT_MAX;
            for(int i = 0; i < n; i++) {
                if(v[i] <= 3) m1 = m1 < abs(v[i] - 3) ? m1 : abs(v[i] - 3);
                else if(v[i] <= 6) m2 = m2 < abs(v[i] - 6) ? m2 : abs(v[i] - 6);
                else if(v[i] <= 9) m3 = m3 < abs(v[i] - 9) ? m3 : abs(v[i] - 9);
                else m4 = m4 < abs(v[i] - 12) ? m4 : abs(v[i] - 12);
            }

            int min = m1 < m2 ? m1 : m2;
            min = min < m3 ? min : m3;
            min = min < m4 ? min : m4;

            cout << min << endl;
        }

        else if(k == 4) {
            int m1 = INT_MAX, m2 = INT_MAX, m3 = INT_MAX;
            for(int i = 0; i < n; i++) {
                if(v[i] <= 4) m1 = m1 < abs(v[i] - 4) ? m1 : abs(v[i] - 4);
                else if(v[i] <= 8) m2 = m2 < abs(v[i] - 8) ? m2 : abs(v[i] - 8);
                else m3 = m3 < abs(v[i] - 12) ? m3 : abs(v[i] - 12);
            }

            int min = m1 < m2 ? m1 : m2;
            min = min < m3 ? min : m3;
            int mm;
            
            if(e >= 2) mm = 0;
            else if(e >= 1) mm = 1;
            else mm = 2;

            min = min < mm ? min : mm;

            cout << min << endl;
        }
        else {
            int m1 = INT_MAX, m2 = INT_MAX;
            for(int i = 0; i < n; i++) {
                if(v[i] <= 5) m1 = m1 < abs(v[i] - 5) ? m1 : abs(v[i] - 5);
                else m2 = m2 < abs(v[i] - 10) ? m2 : abs(v[i] - 10);
            }

            int min = m1 < m2 ? m1 : m2;

            cout << min << endl;
        }
    }
}

int main () {

    solve();

    return 0;
}