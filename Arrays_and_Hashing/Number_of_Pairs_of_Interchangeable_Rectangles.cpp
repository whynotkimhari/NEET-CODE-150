class Solution {
public:
    long long sumTo(int n) {
        if(n < 1) return 0;
        else if(n == 1) return 1;
        else {
            return ((1 + n) / 2.0) * n;
        }
    }

    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        map<double, int> MMap;
        long long ans = 0;
        for(auto rec: rectangles) {
            double ratio = rec[0] / (rec[1] * 1.0);
            MMap[ratio]++;
        }

        for(auto key: MMap) {
            ans += sumTo(key.second - 1);
        }

        return ans;
    }
};
