class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        vector<int> temp(n+1);

        temp[0] = 0;
        int maxi = 0;
        for(int i=0; i<n; i++) {
            temp[i+1] = temp[i] + gain[i];
            maxi = max(maxi, temp[i+1]);
        }
        return maxi;
    }
};