class Solution {
public:
    int findMin(vector<int>& nums) {
        int m = INT_MAX;
        int left = 0, right = nums.size() - 1;
        if(nums[left] <= nums[right]) return nums[left];
        while(left <= right) {
            int mid = (left + right) / 2;
            m = min(m, nums[mid]);

            if(nums[left] <= nums[right]) {
                m = min(m, nums[left]);
                return m;
            }
            if(nums[mid] >= nums[left]) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return m;
    }
};
