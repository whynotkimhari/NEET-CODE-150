class Solution {
public:
    void adv_tokenizer(string s, char del, queue<string> &q) {
        stringstream ss(s);
        string word;
        while (!ss.eof()) {
            getline(ss, word, del);
            if(word.size()) q.push(word);
        }
    }

    string simplifyPath(string path) {
        string ans = "/";
        queue<string> q;
        vector<string> tmp;
        adv_tokenizer(path, '/', q);

        while(!q.empty()) {
            if(q.front() == "..") {
                if(tmp.size()) tmp.pop_back();
            }
            else if(q.front() == ".") ans += "";
            else tmp.push_back(q.front());
            q.pop();
        }

        for(auto &t: tmp) ans = ans + t + "/";
        if(ans.size() > 1) ans = ans.substr(0, ans.size() - 1);

        return ans;
    }
};
