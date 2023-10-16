#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, ans = 0; cin >> n;
    if(n < 1 or n > 200000) return 0;
    for(int i = 0; i < n; i++) {
        string tmp;
        cin >> tmp;
        if(tmp == "Tetrahedron") ans += 4;
        else if(tmp == "Cube") ans += 6;
        else if(tmp == "Octahedron") ans+= 8;
        else if(tmp == "Dodecahedron") ans+= 12;
        else if(tmp == "Icosahedron") ans+= 20;
    }
    cout << ans;
}