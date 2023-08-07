//Solution 1: Cast to string
//Solution 2: Cast to vector
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        if(x < 10) return true;

        vector<int> numV;
        while(x) {
            numV.push_back(x%10);
            x /= 10;
        }

        int left = 0, right = numV.size() - 1;
        while(left <= right) {
            if(numV[left] != numV[right]) return false;
            left++;
            right--;
        }
        return true;
    }
};
