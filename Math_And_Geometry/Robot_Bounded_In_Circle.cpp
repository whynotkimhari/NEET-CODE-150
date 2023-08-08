class Solution {
public:
    bool isRobotBounded(string instructions) {
        pair<int,int> p;
        p = {0,0};
        int face = 1;
        /*
            north : 1
            south : -1
            east : 2
            west : -2
        */

        int loop = 100;

        while(loop--) {
            for(auto i: instructions) {
                if(i == 'G') {
                    if(face == 1) p.second++;
                    else if(face == -1) p.second--;
                    else if(face == 2) p.first++;
                    else p.first--;
                }
                else if(i == 'L') {
                    if(face == 1) face = -2;
                    else if(face == -1) face = 2;
                    else if(face == 2) face = 1;
                    else face = -1;
                }
                else {
                    if(face == 1) face = 2;
                    else if(face == -1) face = -2;
                    else if(face == 2) face = -1;
                    else face = 1;
                }
            }
            if(p.first == 0 && p.second == 0) return true;
        }

        return false;
    }
};
