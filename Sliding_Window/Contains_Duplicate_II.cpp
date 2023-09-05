// Time O(n) Space O(n)
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        set<int> wd;
        int left = 0;

        for(int right = 0; right < nums.size(); right++) {
            // If the window size greater than k
            // Then decrease the size by removing the left-most element (Cause we expanse the window to the right)
            if(right - left > k) {
                // Removing (in memory)
                auto it = wd.find(nums[left]);
                wd.erase(it);

                // Increasing the index (removing in logic/algorithm)
                left++;
            }

            // If the right-most element has existed in the window => return True
            if(wd.find(nums[right]) != wd.end()) {
                return true;
            }

            // Else, add that element to the window
            wd.insert(nums[right]);
        }

        // Return false if no pair is found
        return false;
    }
};
