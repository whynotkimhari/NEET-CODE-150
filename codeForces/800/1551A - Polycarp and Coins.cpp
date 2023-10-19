#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int x; cin >> x;
        int p1 = (x % 3 == 1) ? 1 : 0;
        int p2 = (x % 3 == 2) ? 1 : 0;
        cout << (x / 3) + p1 << " " << (x / 3) + p2 << endl;
    }
}