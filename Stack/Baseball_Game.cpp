class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> points;

        for(auto &op: operations) {
            if(op == "+") {
                int tmp = points.top();
                points.pop();
                int tmp2 = points.top();
                points.push(tmp);
                points.push(tmp + tmp2);
            }

            else if(op == "D") {
                points.push(points.top() * 2);
            }

            else if(op == "C") {
                points.pop();
            }

            else {
                points.push(stoi(op));
            }
        }

        int sum = 0;
        while(!points.empty()) {
            sum += points.top();
            points.pop();
        }

        return sum;
    }
};
