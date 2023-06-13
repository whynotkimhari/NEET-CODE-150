class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int ans = INT_MAX;
        sort(piles.begin(), piles.end());

        
            int start = 1, end = piles[piles.size() - 1];
            while(start <= end) {
                int mid = (start + end) / 2;
                
                unsigned int hours = 0;
                for(int i = 0; i < piles.size(); i++) {
                    hours = hours + ceil(piles[i] * 1.0 / mid);
                }
                if(hours > h) start = mid + 1;
                else {
                    ans = min(ans, mid);
                    end = mid - 1;
                }
            }
        
        return ans;
    }
};
