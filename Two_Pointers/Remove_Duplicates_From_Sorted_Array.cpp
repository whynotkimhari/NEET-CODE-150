class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int answer = nums.size();
        if(nums.size() <= 1) return answer;
        else {
            int checkMax = nums.back();
            int startingPoint = 0;
            while(nums[startingPoint] != checkMax) {
                for(int i = startingPoint + 1; i < nums.size(); i++) {
                    if(nums[i] > nums[startingPoint]) {
                        swap(nums[startingPoint + 1], nums[i]);
                        startingPoint++;
                        break;
                    }
                }
            }
            answer = 0;
            for(int i = 0; i < nums.size(); i++) {
                if(nums[i] != checkMax) answer++;
                else {
                    answer++;
                    break;
                }
            }
        }
        return answer;
    }
};
