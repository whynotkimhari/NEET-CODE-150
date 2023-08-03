class Solution {
public:
    bool validPalindrome(string s) {
        int counter = 1, counter2 = 1;
        int left = 0, right = s.size() - 1;
        int left2 = 0, right2 = s.size() - 1;
        bool is = true, is2 = true;

        while(left <= right) {
            if(s[left] == s[right]) {
                left++;
                right--;
            }
            else {
                counter--;
                if(counter < 0) {
                    is = false;
                    break;
                }
                left++;
            }
        }

        while(left2 <= right2) {
            if(s[left2] == s[right2]) {
                left2++;
                right2--;
            }
            else {
                counter2--;
                if(counter2 < 0) {
                    is2 = false;
                    break;
                }
                right2--;
            }
        }
        return is || is2;
    }
};
