#define mci map<char,int>
class Solution {
public:
    void init(mci &map) {
        for(char i = 'a'; i <= 'z'; i++) map[i] = 0;
    }

    bool check(mci &map1, mci &map2) {
        for(char i = 'a'; i <= 'z'; i++) {
            if(map1[i] != map2[i]) return false;
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        int k = s1.size(), len = s2.size();

        if(k <= len) {
            mci MMap, VVap;
            init(MMap);
            init(VVap);

            for(auto &s: s1) MMap[s]++;
            for(int i = 0; i < k; i++) VVap[s2[i]]++;

            for(int i = 0; i < len - k; i++) {
                if(check(MMap, VVap)) return true;
                else {
                    VVap[s2[i + k]]++;
                    VVap[s2[i]]--;
                }
            }
            return check(MMap, VVap);
        }

        else return false;
    }
};
