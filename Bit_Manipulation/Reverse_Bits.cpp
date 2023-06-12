class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        vector<int> bits;
        for(int i = 0; i < 32; i++) {
            bits.push_back(n%2);
            n /= 2;
        }
        uint32_t ans = 0;
        for(int i = 0; i < 32; i++) {
            ans += bits[i] * pow(2, 31 - i);
        }
        // cout << ans;
        return ans;
    }
};
