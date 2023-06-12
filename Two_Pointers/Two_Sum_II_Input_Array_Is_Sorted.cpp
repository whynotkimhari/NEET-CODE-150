class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> answer;
        int start = 0, end = numbers.size() - 1;

        while(start < end) {
            if(numbers[start] + numbers[end] > target) end--;
            else if(numbers[start] + numbers[end] < target) start++;
            else {
                answer.push_back(start + 1);
                answer.push_back(end + 1);
                break;
            }
        }

        return answer;
    }
};
