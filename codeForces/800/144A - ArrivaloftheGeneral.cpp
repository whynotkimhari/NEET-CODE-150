#include <iostream>
using namespace std;

int main() {
    int n; cin >> n;
    int h[101];
    for (int i =1;i <=n;i++) cin >> h[i];

    int max = 0, min = 200;
    int i_min = -1, i_max = -1;
    for (int i = 1; i<=n;i++) {
        if (h[i] <= min) {
            min = h[i];
            i_min = i;
        }
        if (h[i] > max) {
            max = h[i];
            i_max = i;
        }
    }

    int step = i_max - 1 + n - i_min;
    if (i_max > i_min) --step;
    cout << step;
}