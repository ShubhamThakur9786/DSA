class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0) return 0;
        unordered_set<char> chars;
        int left = 0;
        int maxLen = 0;
        for(int right=0; right<s.size(); right++) {
            while(chars.find(s[right]) != chars.end()) {
                chars.erase(s[left]);
                left++;
            }

            chars.insert(s[right]);
            maxLen = max(maxLen, right-left+1);
        }
        return maxLen;
    }
};