#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> ns(n);
    for(int i = 0; i < n; i++) cin >> ns[i];
    int left = 0, right = n - 1;
    int s1 = 0, s2 = 0;
    bool s1t = true;

    while(left <= right) {
        if(s1t) {
            if(ns[left] > ns[right]) {
                s1 += ns[left];
                left++;
            }
            else {
                s1 += ns[right];
                right--;
            }
        }
        else {
            if(ns[left] > ns[right]) {
                s2 += ns[left];
                left++;
            }
            else {
                s2 += ns[right];
                right--;
            }
        }
        s1t = !s1t;
    }
    cout << s1 << " " << s2;
}