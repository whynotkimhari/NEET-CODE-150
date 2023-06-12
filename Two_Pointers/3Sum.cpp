class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> answer;

        for(int i = 0; i < nums.size(); i++) {
            if(i > 0 && nums[i] == nums[i -1]) continue;
            int start = i + 1, end = nums.size() - 1;
            while(start < end) {
                if(nums[start] + nums[end] + nums[i] == 0) {
                    vector<int> found;
                    found.push_back(nums[start]);
                    found.push_back(nums[end]);
                    found.push_back(nums[i]);
                    answer.push_back(found);
                    start++;
                    while(nums[start] == nums[start - 1] && start < end) start++;
                }

                else if(nums[start] + nums[end] + nums[i] < 0) start++;
                else end--;
            }
        }
        
        return answer;
    }
};
