class Solution {
public:
    pair<int,int> maxAndSumVector(vector<int>& vec) {
        int max = vec[0], sum = vec[0];
        for(int i = 1; i < vec.size(); i++) {
            max = vec[i] < max ? max : vec[i];
            sum += vec[i];
        }
        return {max, sum};
    }

    int shipWithinDays(vector<int>& weights, int days) {
        auto p = maxAndSumVector(weights);
        int last = INT_MAX, pm, cnt, minisum;
        while(p.first <= p.second) {
            pm = (p.first + p.second) / 2;
            cnt = 1;
            minisum = 0;
            for(int i = 0; i < weights.size();) {
                if(minisum + weights[i] <= pm) {
                    minisum += weights[i];
                    i++;
                }
                else {
                    cnt++;
                    minisum = 0;
                }
            }

            if(cnt > days) p.first = pm + 1;
            else {
                last = pm < last ? pm : last;
                p.second = pm - 1;
            }
        }
        return last;
    }
};