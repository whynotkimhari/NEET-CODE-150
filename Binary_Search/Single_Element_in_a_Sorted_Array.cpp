class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        // Because every num has 2-copy
        // => So the size of nums: 2 * n + 1 (odd number)
        // => So each time checking nums[mid], (and its copy)
        // => We firstly eliminate them and then
        // Move to the direction where size is odd
        // Becasue that is where target in

        int len = nums.size();

        if(len == 1) return nums[0];

        int left = 0, right = len - 1;
        int leftSize, rightSize;

        while(left <= right) {
            int mid = (left + right) / 2;

            if(mid >= 1 && mid <= len - 2) {
                if(nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]) return nums[mid];
                else {
                    leftSize = mid;
                    rightSize = len - (mid + 1);
                    if(nums[mid - 1] == nums[mid]) leftSize--;

                    if(leftSize % 2) right = mid - 1;
                    else left = mid + 1;
                }
            }
            else return nums[mid];
        }

        return 0;
    }
};
