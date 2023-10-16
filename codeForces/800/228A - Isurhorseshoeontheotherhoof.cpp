#include <iostream>
using namespace std;
#define ul unsigned long

int main() {
    ul hs[4];
    for (int i = 0;i < 4; i++) {
        cin >> hs[i];
    }

    int count = 0;

    if (hs[0] == hs[1]) ++count;
    if (hs[0] == hs[2]) ++count;
    if (hs[0] == hs[3]) ++count;
    if (hs[1] == hs[2]) ++count;
    if (hs[1] == hs[3]) ++count;
    if (hs[2] == hs[3]) ++count;

    if (count > 3) count = 3;

    if (count == 3 ){
        if ( hs[1] == hs[2] and hs[2] == hs[3] and hs[3] == hs[0]) count += 0;
    
        else --count; 
    }
    cout << count;
}