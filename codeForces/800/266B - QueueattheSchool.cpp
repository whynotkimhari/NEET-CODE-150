#include <iostream>
using namespace std;

int main() {
    int n, t;
    cin >> n >> t;
    char list[51];
    for (int i=1; i<=n; i++) cin >> list[i];

    while (t != 0) {
        int lf = 1, rt = n;
        while (lf < rt) {
            if (list[lf] == 'B' and list[lf+1] == 'G') {
                list[lf] = 'G';
                list[lf+1] = 'B';
                lf += 2;
            }
            else ++lf;
        }
        --t;
    }

    for (int i=1; i<=n; i++) cout << list[i];
}