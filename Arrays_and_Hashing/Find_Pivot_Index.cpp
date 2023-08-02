class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> pre;
        vector<int> bac(nums.size(), 0);
        pre.push_back(0);

        int id = -1;

        for(int i = 1; i < nums.size(); i++) {
            int num = nums[i-1] + pre[i - 1];
            pre.push_back(num);
        }

        for(int i = nums.size() - 2; i >= 0; i--) {
            int num = nums[i+1] + bac[i+1];
            bac[i] = num;
        }

        for(int i = 0; i < nums.size(); i++) {
            if(pre[i] == bac[i]) {
                id = i;
                break;
            }
        }

        return id;
    }
};
