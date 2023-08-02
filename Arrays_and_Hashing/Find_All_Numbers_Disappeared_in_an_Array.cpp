class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> checker(n, 0);
        vector<int> answer;

        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i++) {
            checker[nums[i] - 1] = 1;
        }

        for(int i = 0; i < n; i++) {
            if(checker[i] == 0) answer.push_back(i + 1);
        }

        return answer;
    }
};
