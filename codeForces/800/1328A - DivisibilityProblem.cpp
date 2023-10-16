#include <iostream>
using namespace std;

int main() {
    int t; cin >> t;
    int matrix[10001][3], ans[10001] = {0};
    for (int i = 1; i <= t; i++) {
        for (int j = 1; j <= 2; j++) cin >> matrix[i][j];
    }

    for (int i = 1; i <= t; i++) {
        if(matrix[i][1]%matrix[i][2] != 0) {
            ans[i] = matrix[i][2]*(matrix[i][1]/matrix[i][2] + 1) - matrix[i][1];
        }
    }

    for (int i = 1; i <= t; i++) cout << ans[i] << endl;
}