#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, t; cin >> n >> k;
    int cnt = 0;
    while(n--) {
        cin >> t;
        if(5 - t >= k) cnt++;
    }
    cout << cnt / 3;
}