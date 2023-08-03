class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red = 0, white = 0, blue = 0;
        for(auto &num: nums) {
            if(!num) red++;
            else if(num==1) white++;
            else blue++;
        }
        for(auto &num: nums) {
            if(red) {
                num = 0;
                red--;
            }
            else if(white) {
                num = 1;
                white--;
            }
            else if(blue) {
                num = 2;
                blue--;
            }
        }
    }
};
