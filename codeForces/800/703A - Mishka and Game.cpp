#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    int m = 0, c = 0;
    int a, b;
    while(t--) {
        cin >> a >> b;
        if(a > b) m++;
        if(a < b) c++;
    }
    if(m == c) {
        cout << "Friendship is magic!^^";
        return 0;
    }
    (m > c) ? cout << "Mishka" : cout << "Chris";
}