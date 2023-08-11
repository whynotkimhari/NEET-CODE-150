class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        vector<int> ans;
        int sumM = 0;
        for(auto &r: rolls) sumM += r;

        int fullSize = rolls.size() + n;
        int sumN = fullSize * mean - sumM;
        int c = ceil(sumN/(n*1.0)), f = floor(sumN/(n*1.0));
        if(c > 6 || f > 6 || c <= 0 || f <= 0) return ans;

        if(c == f) {
            while(n--) ans.push_back(c);
            return ans;
        }

        else {
            while(sumN > 0) {
                if(sumN / (f*1.0) == (double)n) {
                    while(n--) ans.push_back(f);
                    return ans;
                }
                else if(sumN / (c*1.0) == (double)n) {
                    while(n--) ans.push_back(c);
                    return ans;
                }
                else {
                    ans.push_back(f);
                    sumN -= f;
                }
                n--;
            }
        }
        return ans;
    }
};
