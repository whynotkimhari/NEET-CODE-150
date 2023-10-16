#include <bits/stdc++.h>
using namespace std;
#define ui unsigned int

int main() {
    ui t; cin >> t;
    vector<ui> vec(t);
    for(int i = 0; i < t; i++) cin >> vec[i];

    for(auto x: vec) {
        string s = to_string(x);
        int cnt = 0;
        vector<ui> values;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] != '0') {
                ++cnt;
                values.push_back((s[i] - '0')*pow(10, s.size() - i - 1));
            }
        }
        cout << cnt << endl;
        for(auto y: values) cout << y << " ";
        cout << endl;
    }
}