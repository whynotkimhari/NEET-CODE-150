class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        sort(nums.begin(), nums.end(), greater<int>());
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == n) {
                n--;
            }
            else {
                ans = n;
                break;
            }
        }
        return ans;
    }
};
