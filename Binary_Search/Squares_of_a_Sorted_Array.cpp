class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> newNums;
        int left = 0, right = nums.size() - 1;
        int leftVal = nums[left] * nums[left];
        int rightVal = nums[right] * nums[right];

        while(left <= right) {
            if(leftVal > rightVal) {
                newNums.push_back(leftVal);
                left++;
                if(left < nums.size())
                    leftVal = nums[left] * nums[left];
            }
            else {
                newNums.push_back(rightVal);
                right--;
                if(right >= 0)
                    rightVal = nums[right] * nums[right];
            }
        }

        reverse(newNums.begin(), newNums.end());
        return newNums;
    }
};
