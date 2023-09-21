class Solution {
public:
    bool isVowel(char t) {
        return (t == 'a') || (t == 'e') || (t == 'i') || (t == 'o') || (t == 'u');
    }

    int maxVowels(string s, int k) {
        int max = INT_MIN, cnt = 0, head = 0, tail = k, len = s.size();
        
        for(int i = 0; i < k; i++) {
            if(isVowel(s[i])) cnt++;
        }

        while(true) {
            if(cnt > max) max = cnt;

            if(tail > len) break;
            if(isVowel(s[head])) cnt--;
            if(isVowel(s[tail])) cnt++;
            head++;
            tail++;
        }

        return max;
    }
};
