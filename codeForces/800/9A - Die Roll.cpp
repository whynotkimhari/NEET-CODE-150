#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b; cin >> a >> b;
    int max = a > b ? a : b;

    cout << (6 - max + 1) / __gcd(6 - max + 1, 6) << "/" << 6 / __gcd(6 - max + 1, 6);
}