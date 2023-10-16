#include <bits/stdc++.h>
using namespace std;

int main() {
    int k,l,m,n,d;
    cin >> k >> l >> m >> n >> d;

    int i_drg[100001] = {0};

    int in_k = 1, in_l = 1, in_m = 1, in_n = 1;
    while(1==1) {
        int ck = k*in_k;
        if (ck <= d) {
            i_drg[ck] = 1;
            ++in_k;
        }
        else break;
    }

    while(2==2) {
        int cl = l*in_l;
        if (cl <= d) {
            i_drg[cl] = 1;
            ++in_l;
        }
        else break;
    }

    while(3==3) {
        int cm = m*in_m;
        if (cm <= d) {
            i_drg[cm] = 1;
            ++in_m;
        }
        else break;
    }

    while(4==4) {
        int cn = n*in_n;
        if (cn <= d) {
            i_drg[cn] = 1;
            ++in_n;
        }
        else break;
    }

    int cnt = 0;
    for (int i =1; i<= d; i++) {
        if (i_drg[i] == 1) ++cnt;
    }

    cout <<cnt;
}