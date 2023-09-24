class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> answer;
        string matchingWord = "";
        int len = searchWord.size();
        sort(products.begin(), products.end());

        for(int i = 0; i < len; i++) {
            matchingWord += searchWord[i];
            vector<string> tmpV;

            for(auto &str: products) {
                if(str.substr(0, i + 1) == matchingWord) tmpV.push_back(str);
                if(tmpV.size() == 3) break;
            }
            answer.push_back(tmpV);
        }
        
        return answer;
    }
};
