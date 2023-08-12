class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string ans = "";

        while(true) {
            if(!a && !b && !c) break;
            if(ans.size() >=2 && ans[ans.size() - 1] == ans[ans.size() - 2]) {
                if(ans[ans.size() - 1] == 'a' && !b && !c) break;
                if(ans[ans.size() - 1] == 'a' && (b || c)) {
                    if(b) {
                        ans += "b";
                        b--;
                    }
                    else {
                        ans += "c";
                        c--;
                    }
                    continue;
                }
                if(ans[ans.size() - 1] == 'b' && !c && !a) break;
                if(ans[ans.size() - 1] == 'b' && (c || a)) {
                    if(c) {
                        ans += "c";
                        c--;
                    }
                    else {
                        ans += "a";
                        a--;
                    }
                    continue;
                }
                if(ans[ans.size() - 1] == 'c' && !b && !a) break;
                if(ans[ans.size() - 1] == 'c' && (b || a)) {
                    if(b) {
                        ans += "b";
                        b--;
                    }
                    else {
                        ans += "a";
                        a--;
                    }
                    continue;
                }
            }
            if(c >= a && c >= b) {
                ans += "c";
                c--;
                continue;
            }
            if(a >= c && a >= b) {
                ans += "a";
                a--;
                continue;
            }
            if(b >= a && b >= c) {
                ans += "b";
                b--;
                continue;
            }
        }
        
        return ans;
    }
};
