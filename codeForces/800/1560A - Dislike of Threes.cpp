#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n; cin >> t;
    int start = 0;
    vector<int> v;
    while(v.size() < 1000) {
        if(!(start % 3 == 0 || start % 10 == 3)) v.push_back(start);
        start++;
    }

    while(t--) {
        cin >> n;
        cout << v[n - 1] << endl;
    }
}