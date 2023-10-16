#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, l, c, d, p, nl, np;
    cin >> n >> k >> l >> c >> d >> p >> nl >> np;

    int cnt = 0;

    int a = k * l, b = c * d;

    while(true) {
        a -= nl;
        b--;
        p -= np;

        if(a >= 0 && b >= 0 && p >= 0)
            cnt++;
        else break;
    }

    cout << cnt / n;
}