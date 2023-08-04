class Solution {
public:
    int mySqrt(int x) {
        if(x==1) return 1;
        long long left = 0, right = x / 2;
        long long close;
        while(left <= right) {
            long long mid = (left + right) / 2;
            if(mid * mid == x) return mid;
            else if(mid * mid > x) right = mid - 1;
            else {
                close = mid;
                left = mid + 1;
            }
        }
        return close;
    }
};
