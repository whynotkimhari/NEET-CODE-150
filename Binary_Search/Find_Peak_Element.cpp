class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int len = nums.size();
        int left = 0, right = len - 1;

        if(len == 1) return 0;

        while(left <= right) {
            int mid = (left + right) / 2;
            if(mid >= 1 && mid <= len - 2) {
                if(nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) return mid;

                else if(nums[mid] <= nums[mid - 1] && nums[mid] <= nums[mid + 1]) {
                    if(nums[mid - 1] >= nums[mid + 1]) right = mid - 1;
                    else left = mid + 1;
                }

                else if(nums[mid] <= nums[mid - 1] && nums[mid] >= nums[mid + 1]) {
                    right = mid - 1;
                }
                
                else if(nums[mid] >= nums[mid - 1] && nums[mid] <= nums[mid + 1]) {
                    left = mid + 1;
                }
            }

            else if(mid < 1) {
                if(nums[mid] > nums[mid + 1]) return mid;
                else left = mid + 1;
            }

            else {
                if(nums[len - 1] > nums[len - 2]) return mid;
                else right = mid - 1;
            }
        }
        return 0;
    }
};
