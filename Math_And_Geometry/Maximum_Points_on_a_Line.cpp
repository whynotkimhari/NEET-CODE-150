#define pii pair<int,int>

class Solution {
public:
    struct PairOfPairsCompare {
        bool operator()(const pair<pii, pii>& p1, const pair<pii, pii>& p2) const {
            if (p1.first != p2.first) {
                return p1.first < p2.first;
            }
            return p1.second < p2.second;
        }
    };
    int maxPoints(vector<vector<int>>& points) {
        if(points.size() == 1) return 1;

        int maxSize = 0;

        map<pair<pii,pii>, vector<pii>, PairOfPairsCompare> oxy;
        vector<pii> pts;
        for(auto &p: points) {
            pii node;
            node.first = p[0];
            node.second = p[1];
            pts.push_back(node);
        }

        for(auto &p1: pts) {
            for(auto &p2: pts) {
                if(p1 == p2) continue;

                int mX = p1.first - p2.first;
                int mY = p1.second - p2.second;

                pair<pii,pii> Pair = {p1,p2};

                oxy[Pair].push_back(p1);
                oxy[Pair].push_back(p2);

                for(auto &p3: pts) {
                    if(p3 == p1 || p3 == p2) continue;
                    

                    int cX = p1.first - p3.first;
                    int cY = p1.second - p3.second;

                    if(cY * mX == mY * cX) {
                        oxy[Pair].push_back(p3);
                    }
                }
            }
        }

        for(auto &key: oxy) {
            if(maxSize < key.second.size()) maxSize = key.second.size();
        }

        return maxSize;
    }
};
