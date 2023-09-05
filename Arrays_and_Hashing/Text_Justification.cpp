#define vs vector<string>

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int i = 0, len = words.size(), sumSize = 0;
        vs tmpV, answer;

        while(i < len) {
            if(!tmpV.size()) {
                tmpV.push_back(words[i]);
                sumSize += words[i].size();
                i++;
            }

            else {
                if(sumSize + 1 + words[i].size() <= maxWidth) {
                    tmpV.push_back(" ");
                    tmpV.push_back(words[i]);
                    sumSize = sumSize + words[i].size() + 1;
                    i++;
                }
                
                else {
                    int cntSpace = 0, spaces, extraSpaces;
                    string tmpS = "";

                    for(auto &s: tmpV) if(s == " ") cntSpace++;

                    if(cntSpace) {
                        spaces = (maxWidth - sumSize) / cntSpace;
                        extraSpaces = (maxWidth - sumSize) % cntSpace;
                    }
                    else {
                        spaces = maxWidth - sumSize;
                        extraSpaces = 0;
                    }
                    

                    for(auto &s: tmpV) {
                        tmpS += s;
                        if(s == " ") {
                            tmpS += string(spaces, ' ');
                            if(extraSpaces) {
                                tmpS += " ";
                                extraSpaces--;
                            }
                        }
                    }

                    if(tmpS.size() < maxWidth) tmpS += string(maxWidth - tmpS.size(), ' ');

                    answer.push_back(tmpS);

                    tmpV.clear();
                    sumSize = 0;
                }
            }
        }
        
        string tmpS = "";
        for(auto &s: tmpV) tmpS += s;
        if(tmpS.size() < maxWidth) tmpS += string(maxWidth - tmpS.size(), ' ');
        answer.push_back(tmpS);

        return answer;
    }
};
