class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> arrayK;
        vector<int> answer;
        while(k) {
            arrayK.push_back(k%10);
            k /= 10;
        }
        reverse(num.begin(), num.end());

        int idNum = 0, idArrayK = 0;
        int r = 0;
        while(idNum < num.size() && idArrayK < arrayK.size()) {
            answer.push_back((arrayK[idArrayK] + num[idNum] + r) % 10);
            r = (arrayK[idArrayK] + num[idNum] + r) / 10;
            idNum++;
            idArrayK++;
        }
        while(idNum < num.size()) {
            answer.push_back((num[idNum] + r) % 10);
            r = (num[idNum] + r) / 10;
            idNum++;
        }
        while(idArrayK < arrayK.size()) {
            answer.push_back((arrayK[idArrayK] + r) % 10);
            r = (arrayK[idArrayK] + r) / 10;
            idArrayK++;
        }
        if(r) {
            answer.push_back(r);
        }
        reverse(answer.begin(), answer.end());
        return answer;
    }
};
