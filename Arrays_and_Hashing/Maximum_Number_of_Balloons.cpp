class Solution {
public:
    int maxNumberOfBalloons(string text) {
        map<char, int> m;
        int count = 0;

        for(auto &ch : text) {
            m[ch]++;
        }
        
        while(true) {
            if(m['b'] > 0 && m['a'] > 0 && m['l'] > 1 && m['o'] > 1 && m['n'] > 0) {
                m['b']--; m['a']--; m['n']--;
                m['l']-=2;m['o']-=2;
                count++;
            }
            else break;
        }

        return count;
    }
};
