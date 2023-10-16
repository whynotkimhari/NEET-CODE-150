#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    string word; cin >> word;

    char ascii[26]; int c = 97;
    int ascii_cnt = 0;
    if (n != word.size()) return 1;

    for (int i=0; i<26; i++) {
        ascii[i] = c;
        ++c;
    }

    for (int i=0; i<word.size(); i++) {
        for (int j=0; j<26; j++) {
            if (tolower(word[i]) == ascii[j]) {
                ascii[j] = -1;
                ++ascii_cnt;
            }
        }
    }

    if (ascii_cnt == 26) {
        cout << "YES";
        return 0;
    }
    cout << "NO";
}