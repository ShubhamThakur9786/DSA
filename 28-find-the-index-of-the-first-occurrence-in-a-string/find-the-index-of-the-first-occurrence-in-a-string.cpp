class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty()) return 0;
        for(int i=0; i<haystack.size(); i++) {
            int j=0;
            while((j<needle.size()) && needle[j] == haystack[i+j]) {
                j++;
            }
            if(needle.size() == j) {
                return i;
            }
        }

        return -1;
    }
};