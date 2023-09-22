#define castll static_cast<long long>
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
      sort(potions.begin(), potions.end());
      vector<int> ans;

      int len = potions.size();
      int l, r, m; bool isExisted;

      for(auto &spell: spells) {
        l = 0;
        r = len - 1;
        isExisted = false;

        while(l <= r) {
          m = (l + r) / 2;

          if(castll(potions[m]) * spell >= success) {

            if(m - 1 >= 0 && castll(potions[m - 1]) * spell < success) {
              isExisted = true;
              ans.push_back(len - m);
              break;
            }

            else if(m == 0) {
              isExisted = true;
              ans.push_back(len);
              break;
            }

            else r = m - 1;
          }

          else l = m + 1;
        }

        if(!isExisted) ans.push_back(0);
        
      }
      return ans;
    }
};
