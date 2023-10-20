#include <bits/stdc++.h>
using namespace std;

bool prime(int x) {
    if(x < 2) return false;
    if(x == 2) return true;

    bool flag = true;

    for(int i = 2; i <= sqrt(x); i++) {
        if(x % i == 0) flag = false;
    }
    return flag;
}

int nextPrime(int x) {
    if(!prime(x)) return nextPrime(x + 1);
    return x;
}

int main() {
    int a, b; cin >> a >> b;
    (nextPrime(a + 1) == b) ? cout << "YES" : cout << "NO";
}