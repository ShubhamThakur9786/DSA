class Solution {
public:
    string expand(string s, int left, int right) {
        while(left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }

        return s.substr(left+1, right-left-1);
    }
    string longestPalindrome(string s) {
        string longest = "";
        for(int i=0; i<s.size(); i++) {
            string oddLen = expand(s, i, i);
            string evenLen = expand(s, i, i+1);

            if(oddLen.size() > longest.size()) longest = oddLen;
            if(evenLen.size() > longest.size()) longest = evenLen;
        }

        return longest;
    }
};