#include <bits/stdc++.h>
using namespace std;

int min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    int n; cin >> n;
    map<int, int> m;
    vector<int> v(n);
    for(int i=0; i<n; i++) {
        cin >> v[i];
        m[v[i]]++;
    }

    int mi = min(m[3], min(m[1], m[2]));
    cout << mi << endl;
    while(mi--) {
        bool has1 = false, has2 = false, has3 = false;
        for(int i = 0; i < n; i++) {
            if(!has1 && v[i] == 1) {
                cout << i + 1 << " ";
                has1 = !has1;
                v[i] = -1;
            }
            if(!has2 && v[i] == 2) {
                cout << i + 1 << " ";
                has2 = !has2;
                v[i] = -1;

            }
            if(!has3 && v[i] == 3) {
                cout << i + 1 << " ";
                has3 = !has3;
                v[i] = -1;
            }

            if(has1 && has2 && has3) {
                cout << endl;
                break;
            }
        }
    }
}
