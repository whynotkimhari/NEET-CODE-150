#include <bits/stdc++.h>
using namespace std;

int Sum_to(int n) {
    int sum = 0;
    for(int i = 1; i < n + 1; i++) sum+= i;
    return sum;
}

int main() {
    int n, k; cin >> n >> k;
    int Sums = (240 - k)/5;
    if(Sum_to(n) <= Sums) cout << n;
    else {
        for(int i = 1; i < n + 1; i++) {
            if(Sum_to(n - i) <= Sums) {
                cout << n - i;
                return 0;
            }
        }
    }
}