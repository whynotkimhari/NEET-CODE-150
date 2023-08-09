class Solution {
public:
    static bool myCmp(int &a, int &b) {
        return to_string(a) + to_string(b) > to_string(b) + to_string(a);
    }
    string largestNumber(vector<int>& nums) {
        string answer = "";
        sort(nums.begin(), nums.end(), myCmp);

        for(auto &n: nums) {
            answer += to_string(n);
        }

        if((answer.size() == 100 && answer[0] == '0') || answer.size() < 10) {
            return to_string(stoll(answer));
        }

        return answer;
    }
};
