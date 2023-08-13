class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> answer;
        unordered_map<string, int> MMap;

        if(s.size() <= 10) return answer;

        for(int i = 0; i < s.size() - 9; i++) {
            MMap[s.substr(i,10)]++;
        }

        for(auto &key: MMap) {
            if(key.second > 1) {
                answer.push_back(key.first);
            }
        }
        
        return answer;
    }
};
