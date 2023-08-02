class Solution {
public:
    static bool mcp(pair<int, int> &a, pair<int,int> &b) {
        return a.second > b.second;
    }

    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<pair<int, int>> vt;
        vt.push_back({nums[0], 1});
        for(int i = 1; i < nums.size();i++) {
            if(vt.back().first == nums[i]) vt.back().second++;
            else vt.push_back({nums[i], 1});
        }

        sort(vt.begin(), vt.end(), mcp);
        return vt[0].first;
    }
};
