class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool isMORE = false;
        for(int i = digits.size() - 1; i >= 0; i--) {
            if(digits[i] < 9) {
                digits[i]++;
                break;
            }
            else {
                digits[i] = 0;
                if(i == 0) isMORE = true;
            }
        }

        if(isMORE) {
            reverse(digits.begin(), digits.end());
            digits.push_back(1);
            reverse(digits.begin(), digits.end());
        }
        return digits;
    }
};
