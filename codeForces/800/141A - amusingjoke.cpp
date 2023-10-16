#include <bits/stdc++.h>
using namespace std;

int main(){
    string ln1, ln2, ln3;
    int al1[26] = {0}, al2[26] = {0};
    cin >> ln1 >> ln2 >> ln3;
    for(int i = 0; i < ln1.size(); i++) al1[ln1[i] - 65]++;
    for(int j = 0; j < ln2.size(); j++) al1[ln2[j] - 65]++;
    for(int z = 0; z < ln3.size(); z++) al2[ln3[z] - 65]++;

    for(int i = 0; i < 26; i++) {
        if(al1[i] != al2[i]) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}