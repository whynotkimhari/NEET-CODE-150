#include <iostream>
using namespace std;

int main() {
    unsigned int k, w;
    long n;
    int sum = 0;
    cin >> k >> n >> w;
    for (int i=1; i<= w; i++) sum += k * i;
    if (n >= sum) cout << 0;
    else cout << sum - n;

}