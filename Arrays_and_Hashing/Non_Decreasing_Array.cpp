class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int cnt = 0;
        for(int i = 1; i < nums.size() - 1; i++) {
            if(!(nums[i-1] <= nums[i] && nums[i] <= nums[i+1])) {  
                if(nums[i-1] >= nums[i] && nums[i] >= nums[i+1]) {
                    if(nums[i] == nums[i+1]) {
                        nums[i-1] = nums[i];
                        cnt++;
                    }
                    else if(nums[i] == nums[i-1]) {
                        nums[i+1] = nums[i];
                        cnt++;
                    }
                    else return false;
                }
                else {
                    if(nums[i-1] >= nums[i] && nums[i] <= nums[i+1]) nums[i-1] = nums[i] - 1;
                    else if(nums[i-1] <= nums[i] && nums[i] >= nums[i+1]) {
                        if(nums[i-1] <= nums[i+1]) nums[i] = nums[i+1];
                        else nums[i+1] = nums[i]+1;
                    }
                    cnt++;
                }
            }
        }

        if(cnt >= 2) return false;
        return true;
    }
};
