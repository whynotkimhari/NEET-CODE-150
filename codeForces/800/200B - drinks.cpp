#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, list[101]; cin >> n;
    double sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> list[i];
        sum += list[i];
    }
    
    cout << setprecision(14) << fixed << sum / n ;
}