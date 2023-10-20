#include <bits/stdc++.h>
using namespace std;

int main() {
    int sum; cin >> sum;
    int i = 1;
    int h = 0;
    while(sum >= (i + 1) * i / 2) {
        sum -= (i + 1) * i / 2;
        i++;
        h++;
    }
    cout << h << endl;
}