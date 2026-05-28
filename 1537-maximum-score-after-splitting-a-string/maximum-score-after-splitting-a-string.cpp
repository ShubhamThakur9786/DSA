class Solution {
public:
    int maxScore(string s) {
        int totalOnes = 0;
        int n = s.size();
        for(int i=0; i<n; i++) {
            if(s[i] == '1') {
                totalOnes++;
            }
        }

        int zeroCnt = 0;
        int oneCnt = 0;
        int result = INT_MIN;
        
        for(int i=0; i<n-1; i++) {
            if(s[i]=='0') {
                zeroCnt++;
            }
            else {
                oneCnt++;
            }
            result = max(result, (zeroCnt + (totalOnes-oneCnt)));
        }
        return result;
    }
};