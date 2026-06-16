class Solution {
public:
    int numberOfSteps(int num) {
        //num -> 0
        int steps = 0;
        while(num) {
            if(num % 2 == 0) {
                //even
                num = num/2;
            }
            else {
                //odd
                num = num-1;
            }
            steps++;
        }
        return steps;
    }
};