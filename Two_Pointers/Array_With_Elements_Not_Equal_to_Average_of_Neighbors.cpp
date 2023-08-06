class Solution {
public:
    bool is(vector<int> &nums) {
        for(int i = 1; i < nums.size() - 1; i++) {
            if(nums[i] == (nums[i - 1] + nums[i + 1]) / 2) return false;
        }
        return true;
    }
    vector<int> rearrangeArray(vector<int>& nums) {
        while(!is(nums)) {
            unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
            shuffle (nums.begin(), nums.end(), std::default_random_engine(seed));
        }
        
        return nums;
    }
};
