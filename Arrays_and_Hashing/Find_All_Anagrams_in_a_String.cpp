class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> answer;
        vector<int> alphaBetaCheck(26,0);
        if(p.size() > s.size()) return answer;
        
        for(auto &c: p) alphaBetaCheck[int(c-'a')]++;

        for(int i = 0; i < s.size() - p.size() + 1; i++) {
            vector<int> alphaBeta(26,0);
            bool flag = true;
            for(int j = i; j < i + p.size(); j++) {
                alphaBeta[int(s[j]-'a')]++;
            }
            for(int z = 0; z < 26; z++) {
                if(alphaBeta[z] != alphaBetaCheck[z]) {
                    flag = false;
                    break;
                }
            }
            if(flag) answer.push_back(i);
        }

        return answer;
    }
};
