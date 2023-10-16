#include <bits/stdc++.h>
using namespace std;

int min(vector<int> x) {
    int minvalue = INT16_MAX;
    for(int i = 0; i < x.size(); i++) if(x[i] < minvalue) minvalue = x[i];
    return minvalue;
}

int max(vector<int> x) {
    int maxvalue = INT16_MIN;
    for(int i = 0; i < x.size(); i++) if(x[i] > maxvalue) maxvalue = x[i];
    return maxvalue;
}

int main() {
    int n; cin >> n;
    vector<int> vec1, vec2(n);
    for(int i = 0; i < n; i++) cin >> vec2[i];
    vec1.push_back(vec2[0]);
    for(int i = 1; i < n; i++) if(vec2[i] > max(vec1) or vec2[i] < min(vec1)) vec1.push_back(vec2[i]);
    cout << vec1.size() - 1;
}