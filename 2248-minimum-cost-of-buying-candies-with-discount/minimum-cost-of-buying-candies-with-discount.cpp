class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end());
        int n = cost.size();
        
        int i=n-1;
        int totalCost = 0;
        int cnt = 0;
        while(i >= 0) {
            cnt++;
            if(cnt == 3) {
                cnt = 0;
            }else {
                totalCost += cost[i];
            }
            i--;
        }
        return totalCost;
    }
};