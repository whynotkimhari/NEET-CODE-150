#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve (){
    // CODE HERE
    int n; cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++) cin >> v[i];
    int max = 0;
    int cnt = 1;
    for(int i = 0; i < n - 1;i++) {
        if(v[i + 1] > v[i]) cnt++;
        else {
            max = max > cnt ? max : cnt;
            cnt = 1;
        }
    }
    max = max > cnt ? max : cnt;

    cout << max << endl;
}

int main () {

    solve();

    return 0;
}