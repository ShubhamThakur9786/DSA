class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_set<char> lower, uper;

        for(auto s : word) {
            if(islower(s)) {
                lower.insert(s);
            }
            else {
                uper.insert(s);
            }
        }

        int count = 0;

        for(char i = 'a'; i<='z'; i++) {
            if(lower.count(i) && uper.count(toupper(i))) {
                count++;
            }
        }
        return count;

    }
};