#include <iostream>
using namespace std;

int main() {
    int n, h;
    int list[1001];
    cin >> n >> h;
    int width = 0;
    
    for (int i=1; i<=n; i++) {
        cin >> list[i];
        if (list[i] > h) width += 2;
        else ++width;
    }

    cout << width;
}