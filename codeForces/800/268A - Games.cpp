#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int teams[31][3] = {0};

    for (int i = 1; i < n + 1; i++) {
        cin >> teams[i][1] >> teams[i][2]; 
    }

    int cnt = 0;
    for (int i = 1;i < n; i++) {
        for (int j = i + 1; j < n + 1; j++) {
            if (teams[i][1] == teams[j][2]) ++cnt;
            if (teams[i][2] == teams[j][1]) ++cnt;
        }
    }

    cout << cnt;
}