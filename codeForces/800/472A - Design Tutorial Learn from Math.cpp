#include <bits/stdc++.h>
using namespace std;

bool isComposite(int x) {
    for(int i = 2; i < x; i++) {
        if(x % i == 0) return true;
    }
    return false;
}

int main() {
    int n; cin >> n;
    for(int i = 3; i < n - 2; i++) {
        if(isComposite(i) && isComposite(n - i)) {
            cout << i << " " << n - i;
            return 0;
        }
    }
}