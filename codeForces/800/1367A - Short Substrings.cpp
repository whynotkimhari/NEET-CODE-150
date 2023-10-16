#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    while(n--) {
        string s; cin >> s;
        string plain = "";
        for(int i = 0; i < s.size() - 1; i+=2) {
            plain = plain + s[i];
        }
        plain += s[s.size() - 1];
        cout << plain << '\n';
    }
}