class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int min = nums[0], max = nums.back() + 1;
        int ptR = nums.size() - 1;
        for(int i = min; i < max; i++) {
            int cntI = 0; int j = 0;
            while(j < nums.size()) {
                if(nums[j] == i) {
                    cntI++;
                    if(cntI > 2) nums[j] = INT_MAX;
                }
                j++;
            }
        }
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++) if(nums[i] == INT_MAX) return i;
        return nums.size();
    }
};
