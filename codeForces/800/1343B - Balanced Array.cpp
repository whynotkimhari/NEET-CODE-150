#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n; cin >> t;
    while(t--) {
        cin >> n;
        if(n % 4) cout << "NO\n";
        else {
            cout << "YES\n";
            vector<int> tmp, tmp2;
            int start = 2;
            int time = n / 2;
            int s1 = 0, s2 = 0;
            while(time--) {
                s1 += start;
                s2 = s2 + start - 1;
                tmp.push_back(start);
                tmp2.push_back(start - 1);
                start += 2;
            }

            
            s2 -= tmp2.back();
            tmp2.pop_back();
            tmp2.push_back(s1 - s2);

            time = n / 2;
            while(time--) {
                cout << tmp.back() << " ";
                tmp.pop_back();
            }
            time = n / 2;
            while(time--) {
                cout << tmp2.back() << " ";
                tmp2.pop_back();
            }
            cout << endl;
        }
    }
}