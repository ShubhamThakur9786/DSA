class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int i=0;
        int j=tokens.size()-1;
        int score = 0;
        int maxScore = 0;
        while(i <= j) {
            if(tokens[i] <= power) {
                score++;
                maxScore = max(score, maxScore);
                power -= tokens[i];
                i++;
            }
            else {
                if(score >= 1) {
                    score--;
                    power += tokens[j];
                    j--;
                }
                else {
                    break;
                }
            }
        }
        return maxScore;
    }
};