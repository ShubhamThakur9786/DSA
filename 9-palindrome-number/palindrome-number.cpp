class Solution {
public:
    bool Solve(long long x) {
        long long originaldata = x;
        long long data = 0;
        while(x > 0) {
            data = (x%10) + data*10;
            x = x/10;
        }
        return originaldata == data;
    }
    bool isPalindrome(int x) {
        if(x < 0) {
            return false;
        }
        return Solve(x);
    }
};