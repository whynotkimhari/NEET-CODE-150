class Solution {
public:
    int arraySign(vector<int>& nums) {
        int answer = 1;

        for(auto &num: nums) {
            if(num < 0) answer *= (-1);
            else if(num == 0) answer = 0;
            else continue; 
        }
        
        return answer;
    }
};
