#include <bits/stdc++.h>
using namespace std;

int main() {
    int x, y; cin >> x >> y;
    bool isBW = true;
    for(int i = 0; i < x * y; i++) {
        char c; cin >> c;
        if(c == 'C' || c == 'M' || c == 'Y') isBW = false;
    }
    !isBW ? cout << "#Color" : cout << "#Black&White";
}