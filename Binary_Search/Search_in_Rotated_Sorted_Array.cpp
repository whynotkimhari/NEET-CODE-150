/// MY REALLY MESSY CODE !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
/// TOO TIRED TO SIMPLIFY IT 
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size();

        if(len == 1) {
            if(nums[0] == target) return 0;
            return -1;
        }

        int left = 0, right = len - 1;
        int L = nums[0], R = nums[len - 1];
        

        while(left <= right) {
            int mid = (left + right) / 2;

            if(nums[mid] == target) return mid;
            if(mid >= 1 && nums[mid - 1] == target) return mid - 1;
            if(mid <= len - 2 && nums[mid + 1] == target) return mid + 1;
            if(target == nums[left]) return left;
            if(target == nums[right]) return right;

            if(L < target && (target < nums[mid] || (mid >= 1 && target < nums[mid - 1]))) {
                right = mid - 1;
                R = nums[right];
            }

            else if(L < target && target > nums[mid] && target > R && nums[mid] < R && nums[mid] < L) {
                right = mid - 1;
                if(right >= 0)
                R = nums[right];
            }

            else if(L < target && target > nums[mid]) {
                
                left = mid + 1;
                if(left < len)
                L = nums[left];
            }

            else if(L > target && target < nums[mid] && L > nums[mid] && R > nums[mid]) {
                right = mid - 1;
                if(right >= 0) {
                    R = nums[right];
                }
            }
            
            else if(L > target && (target < nums[mid] || (mid >= 1 && target < nums[mid - 1]))) {
                
                left = mid + 1;
                if(left < len)
                    L = nums[left];
            }
            else if ((nums[mid] < target || (mid <= len - 2 && nums[mid + 1] < target)) && target <= R) {
                
                left = mid + 1;
                L = nums[left];
                
            }
            else if(L < target && target > nums[mid]) {
                
                right = mid - 1;
                if(right >= 0)
                R = nums[right];
            }
            
            else return -1;
        }
        return -1;
    }
};
