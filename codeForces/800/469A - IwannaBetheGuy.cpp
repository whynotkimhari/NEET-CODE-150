#include <iostream>
using namespace std;

int main() {
    int n, p, q, pset[101], qset[101]; cin >> n >> p;
    if (p!= 0) for (int i =1 ; i<= p; i++) cin >> pset[i];
    cin >> q;
    if (q!= 0) for (int i = 1; i<= q; i++) cin >> qset[i];

    for (int i = 1; i<= n; i++) {
        int count = 0;
        if (p != 0){
            for (int j = 1; j <= p; j++) if (pset[j] == i) ++count;
        }
        
        if (q != 0) {
            for (int j = 1; j <= q; j++) if (qset[j] == i) ++count;
        }

        if (count == 0) {
            cout << "Oh, my keyboard!";
            return 0;
        }
    }
    cout << "I become the guy.";
}