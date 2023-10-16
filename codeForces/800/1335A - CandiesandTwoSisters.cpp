#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    vector<int> vec(t);
    for(int i = 0; i < t; i++) cin >> vec[i];
    for(int i = 0; i < t; i++) cout << (vec[i] - 1)/2 << '\n';
}