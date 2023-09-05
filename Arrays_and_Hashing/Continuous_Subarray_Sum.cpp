// Time O(n^2) Space O(n)
// Using prefix and nested loop to calculate subarray sum -> TLE 
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if(nums.size() < 2) return false;
        vector<int> pre(nums.size());
        pre[0] = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            pre[i] = pre[i-1] + nums[i];
            if(!(pre[i] % k)) return true;
            for(int j = 0; j < i - 1; j++) {
                int tmp = pre[i] - pre[j];
                if(!(tmp % k)) return true;
            }
        }

        return false;
    }
};

// Time O(n) Space O(n)
// Using prefix and HashMap to store { remainder(key) : index(value) } of prefix[i] % k
// Every time a new calculated key has existed in HashMap
// It means that "" new_sum = last_sum + k*n ""
// Because new_sum % k == last_sum % k (k * n % k = 0)
// So that we will find out the answer
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int len = nums.size();

        if(len < 2) return false;
        else if(len == 2) return !((nums[0] + nums[1]) % k);

        vector<int> pre(nums.size());
        map<int,int> MMap;
        

        pre[0] = nums[0];
        for(int i = 1; i < len; i++) {
            pre[i] = pre[i-1] + nums[i];
        }

        for(int i = 0; i < len; i++) {
            int mod = pre[i] % k;
            if(MMap.find(mod) != MMap.end()) {
                if(abs(MMap.find(mod)->second - i) > 1) return true;
            }
            else {
                MMap[mod] = i;
                if(!mod && i) return true;
            }
        }

        return false;
    }
};
