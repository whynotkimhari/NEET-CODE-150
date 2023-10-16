#include <iostream>
using namespace std;

#define ull unsigned long long

int main() {
    ull n; cin >> n;

    if (n%2 == 0) cout << n/2;
    else cout << '-' << (n+1)/2;
}