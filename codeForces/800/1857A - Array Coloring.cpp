#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve (){
    // CODE HERE
    int t; cin >> t;
    while(t--) {
        int sum = 0;
        int n; cin >> n;
        while(n--) {
            int x; cin >> x;
            sum += x;
        }
        sum % 2 ? cout << "NO\n" : cout << "YES\n";
    }
}

int main () {

    solve();

    return 0;
}