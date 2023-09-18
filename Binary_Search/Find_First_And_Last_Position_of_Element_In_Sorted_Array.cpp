class Solution {
public:
    int bs(vector<int> &nums, int target) {
        int left = 0, right = nums.size() - 1;
        while(left <= right) {
            int mid = (left + right) / 2;

            if(nums[mid] == target) return mid;
            else if(nums[mid] > target) right = mid - 1;
            else left = mid + 1;
        }

        return -1;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int firstC = bs(nums, target);
        if(firstC == -1) {
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }

        else {
            int start = firstC, end = firstC;
            for(int i = firstC; i >= 0; i--) {
                if(nums[i] == target) start = i;
            }
            for(int i = firstC; i < nums.size(); i++) {
                if(nums[i] == target) end = i;
            }
            ans.push_back(start);
            ans.push_back(end);

            return ans;
        }
    }
};
