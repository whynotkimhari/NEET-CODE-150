class Solution {
public:
    int reverse(int x) {
        if(!x) return x;
        
        string str = to_string(x);
        
        if(x > 0) ::reverse(str.begin(), str.end());
        else ::reverse(str.begin() + 1, str.end());

        long ans = stol(str);
        if(ans  > 2147483647 || ans < - 2147483648) return 0;
        return ans;
    }
};
