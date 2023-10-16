#include <bits/stdc++.h>
using namespace std;

int maxe(int x, int y) {
    if(x >= y) return x;
    return y;
}

int mine(int x, int y) {
    if(x <= y) return x;
    return y;
}

int main() {
    int a, b; cin  >> a >> b;
    cout << mine(a, b) << " " << (maxe(a, b) - mine(a, b))/2;
}