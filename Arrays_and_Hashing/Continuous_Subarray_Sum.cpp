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
