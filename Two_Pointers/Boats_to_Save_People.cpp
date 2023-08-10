class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int l = 0, r = people.size() - 1, cnt = 0;
        while(l <= r) {
            cnt++;
            if(people[l] == limit) l++;
            else if(people[r] == limit) r--;
            else if(people[l] + people[r] > limit) {
                if(people[l] > people[r]) l++;
                else r--;
            }
            else if(people[l] + people[r] <= limit) {
                l++; r--;
            }
        }
        return cnt;
    }
};
