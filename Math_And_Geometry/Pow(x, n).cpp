class Solution {
public:
    double sq(double x) {
        return x * x;
    }

    double myPow(double x, int n) {
        if(n == 0) return 1;
        else if(n < 0) return (1/x) * myPow(1 / x, (-1) * (n + 1));
        else {
            if(n % 2 == 0) return sq(myPow(x, n / 2));
            else return x * sq(myPow(x, n / 2));
        }
    }
};
