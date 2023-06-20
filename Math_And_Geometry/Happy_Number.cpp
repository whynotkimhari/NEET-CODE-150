class Solution {
public:
    bool isHappy(int n) {
        if(n == 1) return true;
        set<int> seen;
        seen.insert(n);
        while(to_string(n).size() != 0) {
            int sum = 0;
            for(int i = 0; i < to_string(n).size(); i++) {
                sum += (to_string(n)[i] - '0')*(to_string(n)[i] - '0');
            }
            n = sum;
            if(seen.find(n) != seen.end()) return false;
            seen.insert(n);
            if(n == 1) return true;
        }
        return true;
    }
};
