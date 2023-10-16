#include <iostream>
using namespace std;

int main() {
    int matrix[5][5] = {0};
    int onex, oney, muv;
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            cin >> matrix[i][j];
            if (matrix[i][j] == 1) {
                onex = j;
                oney = i;
            }
        }
    }

    muv = 0;
    while(onex != 2 or oney != 2) {
        if (onex > 2) {--onex; ++muv;}
        if (onex < 2) {++onex; ++muv;}
        if (oney > 2) {--oney; ++muv;}
        if (oney < 2) {++oney; ++muv;}
    }

    cout << muv;
}