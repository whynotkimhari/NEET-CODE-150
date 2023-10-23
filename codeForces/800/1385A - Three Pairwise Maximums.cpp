#include <bits/stdc++.h>
using namespace std;
#define ll long long

int max(int x, int y) {
    return x > y ? x : y;
}

int min(int x, int y) {
    return x < y ? x : y;
}

void solve (){
    // CODE HERE
    int a, b, c; cin >> a >> b >> c;
    int m = max(a, max(b, c));
    int cnt = 0;
    if(m == a) cnt++;
    if(m == b) cnt++;
    if(m == c) cnt++;

    if(cnt <= 1) cout << "NO\n";
    else if(cnt == 2) {
        int mn = min(a, min(b, c));
        cout << "YES\n";
        cout << m << " " << mn << " " << mn << endl;
    }
    else {
        cout << "YES\n";
        cout << m << " " << m << " " << m << endl;
    }
}

int main () {

    int t; cin >> t;
    while(t--) solve();

    return 0;
}