class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        vector<int> answerArray(arr.size(), -1);

        for(int i = 0; i < arr.size() - 1; i++) {
            answerArray[i] = *max_element(arr.begin() + i + 1, arr.end());
        } 
        return answerArray;
    }
};
