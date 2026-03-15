class Solution {
public:
    void reverse(vector<char> &s, int st, int end) {
        if(st >= end) {
            return;
        }
        swap(s[st], s[end]);
        reverse(s, st+1, end-1);
    }
    void reverseString(vector<char>& s) {
        return reverse(s, 0, s.size()-1);
    }
};