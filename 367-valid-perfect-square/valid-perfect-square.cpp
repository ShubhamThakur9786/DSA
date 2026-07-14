class Solution {
public:
    bool isPerfectSquare(int num) {
        int st = 0;
        int end = num;

        while(st <= end) {
            int mid = st + (end-st)/2;
            if((long long)mid*mid == num) {
                return true;
            }
            else if((long long)mid*mid < num) {
                st = mid+1;
            }
            else {
                end = mid-1;
            }
        }
        return false;
    }
};