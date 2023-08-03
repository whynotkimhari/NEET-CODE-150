class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int left = 0, right = nums.size() - 1;
        int cnt = 0;

        while(left <= right) {
            if(nums[left] != val && nums[right] != val) {
                left++;
                continue;
            }
            if(nums[left] == val && nums[right] != val) {
                swap(nums[left], nums[right]);
                left++;
                continue;
            }
            if(nums[left] != val && nums[right] == val) {
                right--;
                continue;
            }
            if(nums[left] == val && nums[right] == val) {
                right--;
                continue;
            }
        }

        for(auto &num:nums) {
            if(num != val) cnt++;
            else break;
        }

        return cnt;
    }
};
