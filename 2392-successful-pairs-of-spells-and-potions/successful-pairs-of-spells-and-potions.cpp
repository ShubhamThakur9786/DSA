class Solution {
public:
    int BS(vector<int>& potions, long long minPot) {
        int st = 0;
        int end = potions.size()-1;
        int ans = -1;

        while(st <= end) {
            int mid = st + (end-st)/2;
            if(potions[mid] >= minPot) {
                ans = mid;
                end = mid-1;
            }
            else {
                st = mid+1;
            }
        }
        return ans;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> pairs;

        sort(potions.begin(), potions.end());

        for(int i=0; i<spells.size(); i++) {
            long long minPot = ceil((1.0*success)/spells[i]);
            int idx = BS(potions, minPot);
            if(idx != -1) {
                pairs.push_back(potions.size()-idx);
            }
            else {
                pairs.push_back(0);
            }
        }

        return pairs;
    }
};