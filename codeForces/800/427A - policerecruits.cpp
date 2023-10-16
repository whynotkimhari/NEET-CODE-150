#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> events(n);
    for(int i = 0; i < n ;i ++) cin >> events[i];
    int polices = 0, crimes = 0;
    for(int i = 0; i < n ; i++) {
        if(events[i] != -1) polices+= events[i];
        else {
            if(polices == 0) ++crimes;
            else --polices;
        }
    }
    cout << crimes;
}