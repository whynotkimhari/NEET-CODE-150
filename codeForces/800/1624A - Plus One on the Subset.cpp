#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    int n, x;
    while(t--) {
        int max = INT_MIN, min = INT_MAX;
        cin >> n;
        while(n--) {
            cin >> x;
            if(x > max) max = x;
            if(x < min) min = x;
        }
        cout << max - min << endl;
    }
}