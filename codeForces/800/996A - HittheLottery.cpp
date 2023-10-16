#include <iostream>
using namespace std;

int main() {
    int n; cin >> n;
    int c100,c20,c10,c5,c1;

    c100 = n / 100;
    n = n - c100*100;

    c20 = n / 20;
    n = n - c20*20;

    c10 = n / 10;
    n = n - c10*10;

    c5 = n / 5;
    n = n - c5*5;

    c1 = n;

    cout << c100 + c20 + c10 + c5 + c1;
}