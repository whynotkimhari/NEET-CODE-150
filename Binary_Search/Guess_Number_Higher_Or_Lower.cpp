/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        unsigned int left = 1, right = n;
        while(true) {
            unsigned int mid = (left + right) / 2;
            unsigned int ans = guess(mid);

            if(!ans) {
                return mid;
            }

            else if(ans == 1) {
                left = mid + 1;
            }

            else {
                right = mid - 1;
            }
        }
        return 0;
    }
};
