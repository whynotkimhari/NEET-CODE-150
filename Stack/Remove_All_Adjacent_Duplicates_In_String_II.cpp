class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> st; // Use a stack of pairs (character, count)
        
        for (char c : s) {
            if (!st.empty() && st.top().first == c) {
                st.top().second++; // Increment the count if the current character matches the top of the stack
                if (st.top().second == k) {
                    st.pop(); // If count reaches k, pop the character from the stack
                }
            } else {
                st.push({c, 1}); // Otherwise, push the character with a count of 1
            }
        }
        
        string result = "";
        while (!st.empty()) {
            // Build the result string by repeating characters based on their counts in the stack
            result = string(st.top().second, st.top().first) + result;
            st.pop();
        }
        
        return result;
    }
};
