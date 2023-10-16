#include <bits/stdc++.h>
using namespace std;
int max(int a, int b) {
    return a > b ? a : b;
}
int main() {
    int a, b, c, d; cin >> a >> b >> c >> d;
    int m = max(a, max(b, max(c, d)));
    if(m - a > 0) {
        cout << m - a << " ";
    }
    if(m - b > 0) {
        cout << m - b << " ";
    }
    if(m - c > 0) {
        cout << m - c << " ";
    }
    if(m - d > 0) {
        cout << m - d << " ";
    }
}