#include <iostream>
using namespace std;

int main() {
    int n; cin >> n;
    int list[101], ans[101] = {0};

    for (int i = 1; i<=n; i++) {
        cin >> list[i];
        ans[list[i]] = i;
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
}