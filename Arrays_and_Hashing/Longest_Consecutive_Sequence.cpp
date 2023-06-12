class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        if(nums.size()==1) return 1;
        sort(nums.begin(), nums.end());
        vector<int> ps;
        for(int i = 0; i < nums.size() - 1; i++) {
            ps.push_back(nums[i]-nums[i+1]);
        }
        int cnt = 0;
        int maxe = 0;
        for(int i = 0; i < ps.size(); i++) {
            if(ps[i] == -1) cnt++;
            else if(ps[i] == 0) continue;
            else cnt = 0;
            maxe = max(cnt, maxe);
        }
        return maxe + 1;
    }
};
