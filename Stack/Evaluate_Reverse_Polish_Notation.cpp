class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> operands;

        for(auto &token: tokens) {
            if(token != "+" && token != "-" && token != "*" && token != "/") {
                int digit = stoi(token);
                operands.push(digit);
            }
            else {
                auto d1 = operands.top(); operands.pop();
                auto d2 = operands.top(); operands.pop();

                if(token == "+") {
                    operands.push(d1 + d2);
                }
                else if(token == "-") {
                    operands.push(d2 - d1);
                }
                else if(token == "*") {
                    operands.push(d1 * d2);
                }
                else if(token == "/") {
                    operands.push(d2 / d1);
                }
            }
        }

        return operands.top();
    }
};
