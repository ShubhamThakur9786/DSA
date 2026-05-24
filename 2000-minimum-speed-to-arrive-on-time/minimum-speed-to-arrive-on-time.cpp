class Solution {
public:

    bool possible(vector<int>& dist, double hour, int mid) {
        int n = dist.size();
        double total = 0;
        for(int i=0; i<dist.size()-1; i++) {
            total += ceil((double)dist[i]/mid);
        }
        total += (double)dist[n-1]/mid; 
        return total <= hour;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int st = 1;
        int end = 1e7;

        int ans = -1;
        while(st <= end) {
            int mid = st+(end-st)/2;
            if(possible(dist, hour, mid)) {
                ans = mid;
                end = mid-1;
            }
            else {
                st = mid+1;
            }
        }
        return ans;
    }
};