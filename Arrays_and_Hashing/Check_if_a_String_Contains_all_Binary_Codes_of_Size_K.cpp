class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> container;

        if(k > s.size()) return false;

        for(int i = 0 ; i < s.size() - k + 1; i++) {
            container.insert(s.substr(i, k));
        }

        if(log2(container.size()) != k) return false;
        return true;
    }
};
