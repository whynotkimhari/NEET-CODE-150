// Time O(n^2) Space O(1)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cnt = 0, len = nums.size();
        for(int i = 0; i < len; i++) {
            int sum = 0;
            for(int j = i; j < len; j++) {
                sum += nums[j];
                if(sum == k) cnt++;
            }
        }
        return cnt;
    }
};

// Time O(n) Space O(n)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int> MMap = {
            {0, 1},
        };

        int currSum = 0, answer = 0;

        for(auto num: nums) {
            currSum += num;
            answer += MMap[currSum - k];
            MMap[currSum]++;
        }

        return answer;
    }
};
