class Solution {
public:
    // Upper bound BS
    char nextGreatestLetter(vector<char>& letters, char target) {
        int len = letters.size();
        int left = 0, right = len - 1;
        char ans = letters[0];

        while(left <= right) {
            int mid = (left + right) / 2;

            // This case maybe our answer, so we store it
            // And then move to the left to find the smaller one
            if(letters[mid] > target) {
                ans = letters[mid];
                right = mid - 1;
            }

            // In this case, this is definitely not our answer
            // So we move to the right (to find the larger ones)
            // And dismiss all the lefts
            else left = mid + 1;
        }

        return ans;
    }
};
