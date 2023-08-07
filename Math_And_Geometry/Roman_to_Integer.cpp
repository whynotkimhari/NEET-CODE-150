class Solution {
public:
    int romanToInt(string s) {
        map<char, int> romanLetter {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        int num = 0;
        int i = 0;
        while(i < s.size()) {
            if(s[i]=='I') {
                if(s[i+1]=='V') {
                    num += 4;
                    i+=2;
                }
                else if(s[i+1]=='X') {
                    num += 9;
                    i+=2;
                }
                else {
                    num += romanLetter[s[i]];
                    i++;
                }
            }
            else if(s[i]=='X') {
                if(s[i+1]=='L') {
                    num += 40;
                    i+=2;
                }
                else if(s[i+1]=='C') {
                    num += 90;
                    i+=2;
                }
                else {
                    num += romanLetter[s[i]];
                    i++;
                }
            }
            else if(s[i]=='C') {
                if(s[i+1]=='D') {
                    num += 400;
                    i+=2;
                }
                else if(s[i+1]=='M') {
                    num += 900;
                    i+=2;
                }
                else {
                    num += romanLetter[s[i]];
                    i++;
                }
            }
            else {
                num += romanLetter[s[i]];
                i++;
            }
        }

        return num;
    }
};
