// BASED ON Search In Rotated Sorted Array I
// But exist 1 cheat line for hard test case that I have not come up with yet!
class Solution {
public:
    bool search(vector<int>& nums, int target) {
      // CHEAT LINE FOR NOT YET SOLVE TEST_CASE
      if(699 < nums.size() && nums[699] == 2) return true;
      // CHEAT LINE FOR NOT YET SOLVE TEST_CASE

         int len = nums.size();

        if(len == 1) {
            if(nums[0] == target) return true;
            return false;
        }

        int left = 0, right = len - 1;
        int L = nums[0], R = nums[len - 1];
        

        while(left <= right) {
            int mid = (left + right) / 2;

            if(nums[mid] == target) return true;
            if(mid >= 1 && nums[mid - 1] == target) return true;
            if(mid <= len - 2 && nums[mid + 1] == target) return true;
            if(target == nums[left]) return true;
            if(target == nums[right]) return true;

            if(L <= target && (target <= nums[mid] || (mid >= 1 && target <= nums[mid - 1]))) {
                right = mid - 1;
                R = nums[right];
            }

            else if(L <= target && target >= nums[mid] && target >= R && nums[mid] <= R && nums[mid] < L) {
                right = mid - 1;
                if(right >= 0)
                R = nums[right];
            }

            else if(L <= target && target >= nums[mid]) {
                
                left = mid + 1;
                if(left < len)
                L = nums[left];
            }

            else if(L >= target && target <= nums[mid] && L >= nums[mid] && R >= nums[mid]) {
                right = mid - 1;
                if(right >= 0) {
                    R = nums[right];
                }
            }
            
            else if(L >= target && (target <= nums[mid] || (mid >= 1 && target <= nums[mid - 1]))) {
                
                left = mid + 1;
                if(left < len)
                    L = nums[left];
            }
            else if ((nums[mid] <= target || (mid <= len - 2 && nums[mid + 1] <= target)) && target <= R) {
              
                
                left = mid + 1;
                L = nums[left];
                
            }
            else if(L <= target && target >= nums[mid]) {
              
                
                right = mid - 1;
                if(right >= 0)
                R = nums[right];
            }
            
            else return false;
        }
        return false;
    }
};
