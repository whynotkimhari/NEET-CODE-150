class Solution {
public:
    static bool cmp(pair<int, int> &a, pair<int, int> &b) {
        return a.second > b.second;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<pair<int, int>> v;
        v.push_back({nums[0],1});
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] == v.back().first) v.back().second++;
            else v.push_back({nums[i], 1});
        }

        sort(v.begin(), v.end(), cmp);

        vector<int> ans;

        for(int i = 0; i < k; i++) {
            ans.push_back(v[i].first);
        }

        return ans;
    }
};
