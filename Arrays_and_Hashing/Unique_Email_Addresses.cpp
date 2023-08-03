class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        set<string> validEmails;

        for(auto &email: emails) {
            bool local  = true;
            bool pass = false;
            string e = "";
            for(int i = 0; i < email.size(); i++) {
                if(local) {
                    if(email[i] == '.') continue;
                    else if(email[i] == '+') {
                        pass = true;
                    }
                    else if(email[i] == '@') {
                        e = e + email[i];
                        local = false;
                    }
                    else {
                        if(!pass)
                            e = e + email[i];
                    }
                }
                else e = e + email[i];
            }
            validEmails.insert(e);
        }

        return validEmails.size();
    }
};
