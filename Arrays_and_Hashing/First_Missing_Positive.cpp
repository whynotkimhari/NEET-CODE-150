class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int start = 1;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] <= 0) continue;
            if(start != nums[i]) {
                if(nums[i] > start) {
                    return start;
                }
            }
            else start++;
        }
        return start;
    }
};
