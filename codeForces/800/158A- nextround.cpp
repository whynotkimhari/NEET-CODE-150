#include <iostream>
using namespace std;

int main() {
    int n, k;
    int score[50];
    int cnt = 0;
    cin >> n >> k;

    for(int i = 1; i <= n; i++) {
        cin >> score[i];
    }

    for(int i = 1; i <= n; i++) {
        if(score[i] >= score[k] and score[i] > 0) ++cnt;
    }

    cout << cnt;
}