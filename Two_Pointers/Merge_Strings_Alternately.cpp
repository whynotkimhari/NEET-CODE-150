class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i = 0, j = 0;
        string mergeText = "";

        while(i < word1.size() && j < word2.size()) {
            mergeText = mergeText + word1[i];
            mergeText = mergeText + word2[j];
            i++;j++;
        }

        while(i < word1.size()) {
            mergeText = mergeText + word1[i];
            i++;
        }

        while(j < word2.size()) {
            mergeText = mergeText + word2[j];
            j++;
        }

        return mergeText;
    }
};
