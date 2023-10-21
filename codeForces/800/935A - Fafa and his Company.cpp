#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve (){
    // CODE HERE
    int n; cin >> n;
    int cnt = 0;
    for(int i = 1; i < n; i++) {
        if((n - i) / i == (n - i) / (i * 1.0)) cnt++;
    }
    cout << cnt;
}

int main () {

    solve();

    return 0;
}