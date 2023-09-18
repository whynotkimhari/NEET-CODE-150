#define ll long long
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int len = nums.size();
        vector<ll> fix(len, 0);
        ll sum = 0;

        if(nums[0] == 0) fix[0] = 1;
        sum += fix[0];

        for(int i = 1; i < len; i++) {
            if(!nums[i]) fix[i] = fix[i - 1] + 1;
            sum += fix[i];
        }

        return sum;
    }
};
