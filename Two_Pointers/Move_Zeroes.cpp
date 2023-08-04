class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if(nums.size() <= 1) return;
        else {
            int p1 = 0, p2 = 1;
            while(true) {
                if(p1 >= nums.size() || p2 >= nums.size()) break;
                if(nums[p1] && nums[p2]) {
                    p2++;
                    continue;
                }
                if(nums[p1] && !nums[p2]) {
                    p1++;
                    continue;
                }
                if(!nums[p1] && nums[p2]) {
                    swap(nums[p1], nums[p2]);
                    p2++;
                    p1++;
                    continue;
                }
                if(!nums[p1] && !nums[p2]) {
                    p2++;
                    continue;
                }
            }
        }
    }
};
