#include <iostream>
using namespace std;

int main() {
    int n;
    int inout = 0, capacity = 0, INOUT[2001];
    cin >> n;
    
    for (int i = 1; i<=2*n;i++) cin >> INOUT[i];
    
    for (int i = 1; i<=2*n-2;i+=2) {
        inout = inout -INOUT[i] + INOUT[i+1];
        if (inout > capacity) capacity = inout;
    }

    cout << capacity;
}