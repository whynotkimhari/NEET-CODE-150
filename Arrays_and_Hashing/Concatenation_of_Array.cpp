class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> newArrays(2*nums.size(),0);

        for(int i = 0; i < nums.size(); i++) {
            newArrays[i] = nums[i];
            newArrays[i + nums.size()] = nums[i];
        }

        return newArrays;
    }
};
