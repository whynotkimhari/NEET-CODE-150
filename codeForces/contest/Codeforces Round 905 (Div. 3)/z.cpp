#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve (){
    // CODE HERE
    int t; cin >> t;
    bool existAll = false;
    map<pair<int, int>, int> m;

    while(t--) {
        char op;
        int l, r; cin >> op >> l >> r;
        if(op == '+') m[{l, r}]++;
        else m[{l, r}]--;

        if(m.size() == 1) cout << "NO\n";
        else {
            if(op == '+') {
                if(existAll) cout << "YES\n";
                else {
                    bool exist = false;
                    for(auto &k: m) {
                        for(auto &v: m) {
                            if(k != v && k.second && v.second) {
                                if(k.first.second < v.first.first || k.first.first > v.first.second) {
                                    exist = true;
                                    break;
                                }
                            }
                            // cout << "(" << k.first.first << "," << k.first.second << ") " << "(" << v.first.first << "," << v.first.second << ") " << endl;
                        }
                        if(exist) break;
                    }

                    existAll = exist;
                    exist ? cout << "YES\n" : cout << "NO\n";
                }
            }
            else {
                bool exist = false;
                for(auto &k: m) {
                    for(auto &v: m) {
                        if(k != v && k.second && v.second) {
                            if(k.first.second < v.first.first || k.first.first > v.first.second) {
                                exist = true;
                                break;
                            }
                        }
                        // cout << "(" << k.first.first << "," << k.first.second << ") " << "(" << v.first.first << "," << v.first.second << ") " << endl;
                    }
                    if(exist) break;
                }

                existAll = exist;
                exist ? cout << "YES\n" : cout << "NO\n";
            }
        }
    }
}

int main () {

    solve();

    return 0;
}