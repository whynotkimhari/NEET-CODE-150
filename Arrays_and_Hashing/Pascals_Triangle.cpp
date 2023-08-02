class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> answer;

        vector<int> v;
        v.push_back(1);
        answer.push_back(v);

        if(numRows == 1) {
            return answer;
        }

        vector<int> v2;
        v2.push_back(1);
        v2.push_back(1);
        answer.push_back(v2);

        if (numRows == 2) {
            return answer;
        }

        if (numRows > 2) {
            numRows -= 2;
            cout << numRows << endl;
            while(numRows--) {
                vector<int> z;
                z.push_back(1);
                for(int i = 0; i < answer.back().size() - 1; i++) {
                    z.push_back(answer.back()[i] + answer.back()[i + 1]);
                }
                z.push_back(1);
                answer.push_back(z);
            }
        }

        return answer;
    }
};
