class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxSize = 0, i = 0;
        string tmp = "";

        while(i < s.size()) {
            // If the char has already existed in tmp string
            // First storing it size for comparison
            // Then remove it (the old duplicate) out of the string
            // Or exactly is set tmp string to new string
            // Which is old's substring start from where duplicate occur + 1
            if(tmp.find(s[i]) != string::npos) {
                maxSize = (maxSize > tmp.size()) ? maxSize : tmp.size();
                tmp = tmp.substr(tmp.find(s[i]) + 1);
            }

            tmp += s[i];
            i++;
        }
        return (maxSize > tmp.size()) ? maxSize : tmp.size();
    }
};
