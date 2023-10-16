#include <iostream>
using namespace std;

int main() {
    int n; cin >> n;
    int list[100001];
    int clus = 1;
    for (int i = 1; i <= n; i++) {
        cin >> list[i];
        if (i >= 2 && list[i] != list[i-1]) ++clus;
    }
    cout << clus;
}