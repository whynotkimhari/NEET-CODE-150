#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int sum = 0; int max = -1;

    for(int i = 0; i < n; i++) {
        int t; cin >> t;
        sum += t;
        (max < t) ? max = t : max = max;
    }

    cout << max * n - sum;
}