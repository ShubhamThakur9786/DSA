class Solution {
public:
    string smallestPalindrome(string s) {
        map<char, int> freq;
        int n = s.size();
        string ans(n, ' ');

        for(int i=0; i<n; i++) {
            freq[s[i]]++;
        }

        int left = 0;
        int right = n-1;
        for(auto &[ch, cnt] : freq) {
            while(cnt >= 2) {
                ans[left] = ch;
                ans[right] = ch;
                cnt -= 2;
                left++;
                right--;
            }
        }

        for(auto &[ch, cnt] : freq) {
            if(cnt == 1) {
                ans[n/2] = ch;
            }
        }
        return ans;
    }
};