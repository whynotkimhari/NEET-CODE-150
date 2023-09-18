class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0, checker = nums[0];
        int len = nums.size();
        for(int i = 0; i < len; i++) {
            if(nums[i] > checker) checker = nums[i];
            sum += nums[i];
        }

        if(sum < target) return 0;
        if(sum == target) return len;
        if(checker >= target) return 1;

        int wd = nums[0];
        int left = 0;
        int minSubLen = INT_MAX;
        for(int right = 1; right < len; right++) {
            if(wd < target) {
                wd += nums[right];
            }
            if(wd >= target) {
                while(wd >= target) {
                    minSubLen = (minSubLen < (right - left + 1)) ? minSubLen : (right - left + 1);
                    wd -= nums[left];
                    left++;
                }
            }
        }

        while(wd >= target) {
            minSubLen = (minSubLen < (len - left)) ? minSubLen : (len - left);
            wd -= nums[left];
            left++;
        }

        return minSubLen;
    }
};
