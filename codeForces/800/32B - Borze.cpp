#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;

    string parse = "";

    int id = 0;
    while(id < s.size()) {
        if(s[id] == '.') parse += '0';
        else {
            if(id + 1 < s.size() && s[id + 1] == '.') {
                parse += '1';
                id++;
            }
            else {
                parse += '2';
                id++;
            }
        }
        id++;
    }

    cout << parse << endl;


}