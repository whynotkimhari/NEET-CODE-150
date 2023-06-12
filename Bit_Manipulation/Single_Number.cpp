class Solution {
public:
    static bool mcp(pair<int,int> &a, pair<int,int> &b) {
        return a.second < b.second;
    }

    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<pair<int, int>> v;
        v.push_back({nums[0], 1});
        
        for(int i = 1; i < nums.size(); i++) {
            if(v.back().first == nums[i]) v.back().second++;
            else v.push_back({nums[i], 1});
        }

        sort(v.begin(), v.end(), mcp);
        return v[0].first;
    }
};
