class Solution {
public:
    static bool cmp(pair<int, int> &a, pair<int, int> &b) {
        return a.second < b.second;
    }
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> newNums;
        vector<int> answer;
        for(int i = 0; i < nums.size(); i++) newNums.push_back({i, nums[i]});
        sort(newNums.begin(), newNums.end(), cmp);
        int start = 0, end = newNums.size() - 1;
        while(start < end) {
            if(newNums[start].second + newNums[end].second > target) end--;
            else if(newNums[start].second + newNums[end].second < target) start++;
            else {
                answer.push_back(newNums[start].first);
                answer.push_back(newNums[end].first);
                break;
            }
        }
        return answer;
    }
};
