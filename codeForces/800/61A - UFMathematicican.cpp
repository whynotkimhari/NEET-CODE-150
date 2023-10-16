#include <iostream>
using namespace std;

int main() {
    string n1,n2; cin >> n1 >> n2;
    
    if (n1.size() != n2.size()) return 1;

    for (int i = 0; i < n1.size(); i++) {
        if (n1[i] != n2[i]) cout << 1;
        else cout << 0;
    }
}