class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        if(k == 1) return 0;

        sort(nums.begin(), nums.end());

        int l = 0, r = l + k - 1;
        int min = INT_MAX;
        while(r < nums.size()) {
            if(nums[r] - nums[l] < min) min = nums[r] - nums[l];
            r++; l++;
        }
        return min;
    }
};
