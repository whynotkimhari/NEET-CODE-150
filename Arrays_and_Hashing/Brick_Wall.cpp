class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int answer = INT_MAX;
        bool allSameSize = true;
        map<int, int> MMap;
        
        int checkSize = wall[0].size();
        for(int i = 0; i < wall.size(); i++) {
            int c = 0;
            if(wall[i].size() != checkSize) allSameSize = false;
            for(int j = 0; j < wall[i].size(); j++) {
                c += wall[i][j];
                if(j != wall[i].size() - 1) MMap[c]++;
            }
        }

        if(allSameSize) {
            if(checkSize == 1) return wall.size();
        }


        for(auto &key: MMap) {
            if(answer > wall.size() - key.second) answer = wall.size() - key.second;
        }

        return answer;
    }
};
