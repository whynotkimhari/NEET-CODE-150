class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size(), 0);
        stack<pair<int, int>> stp;

        for(int i = 0; i < temperatures.size(); i++) {
            while(!stp.empty() && stp.top().first < temperatures[i]) {
                ans[stp.top().second] = i - stp.top().second;
                stp.pop(); 
            }
            stp.push({temperatures[i], i});
        }

        return ans;
    }
};
