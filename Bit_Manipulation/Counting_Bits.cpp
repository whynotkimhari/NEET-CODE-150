## Solution 1: O(nlogn)
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i = 0; i < n + 1; i++) {
            int cnt = 0;
            int e = i;
            while(e != 0) {
                cnt += e % 2;
                e /= 2;
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};

## Solution 2: better
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;

        for(int i = 0; i < n + 1; i++) {
            ans.push_back(__builtin_popcount(i));
        }

        return ans;
    }
};
