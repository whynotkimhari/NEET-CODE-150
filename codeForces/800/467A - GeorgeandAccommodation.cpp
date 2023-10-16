#include <iostream>
using namespace std;

int main() {
    int n; cin >> n;
    int list[201];
    int cnt =  0;
    for (int i=1; i<= 2*n; i++) cin >> list[i];

    for (int i=1; i<= 2*n - 1; i+=2) {
        if (list[i+1] - list[i] >= 2) ++cnt;
    }

    cout << cnt;
}