class Solution {
public:
    /*
     * @param strs: a list of strings
     * @return: encodes a list of strings to a single string.
     */
    string encode(vector<string> &strs) {
        // write your code here
        string encoded_str = "";
        for(auto str : strs) {
            encoded_str = encoded_str + to_string(str.size()) + "#" + str;
        }
        return encoded_str;
    }

    /*
     * @param str: A string
     * @return: decodes a single string to a list of strings
     */
    vector<string> decode(string &str) {
        // write your code here
        vector<string> decoded_str;
        string word = "";
        int i = 0;
        while(i < str.size()) {
            auto j = i;
            while(str[j] != '#') j++;
            int len = stoi(str.substr(i, j - i));
            string word = str.substr(j + 1, len);
            decoded_str.push_back(word);
            i = j + 1 + len;
        }
        return decoded_str;
    }
};
