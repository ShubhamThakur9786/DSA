class Solution {
public:
    int number(char x) {
        if(x == 'I') {
            return 1;
        }
        else if(x == 'V') {
            return 5;
        }
        else if(x == 'X') {
            return 10;
        }
        else if(x == 'L') {
            return 50;
        }
        else if(x == 'C') {
            return 100;
        }
        else if(x == 'D') {
            return 500;
        }
        else {
            return 1000;
        }
    }
    int romanToInt(string s) {
        int sum = 0;
        int i = 0;

        while(i < s.size()-1) {
            if(number(s[i]) < number(s[i+1])) {
                sum -= number(s[i]);
            }
            else {
                sum += number(s[i]);
            }
            i++;
        }
        sum += number(s[s.size()-1]);
        return sum;
    }
};