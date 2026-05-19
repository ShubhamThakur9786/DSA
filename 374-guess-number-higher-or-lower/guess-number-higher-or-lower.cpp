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
        int l = 0;
        int e = n;
        while(l <= e) {
            int guess_no = l+(e-l)/2;
            int val = guess(guess_no);

            if(val == 0) {
                return guess_no;
            }
            else if(val == -1) {
                e = guess_no-1;
            }
            else {
                l = guess_no+1;
            }
        }
        return -1;
    }
};