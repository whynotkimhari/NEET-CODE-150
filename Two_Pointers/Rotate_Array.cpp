class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> num2(nums.size(),0);
        for(int i = 0; i < nums.size(); i++) {
            num2[(i + k) % nums.size()] = nums[i];
        }
        
        for(int i = 0; i < nums.size(); i++) {
            nums[i] = num2[i];
        }

    }
};
