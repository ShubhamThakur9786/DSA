class Solution {
public:
    bool checkPoss(vector<int> time, int totalTrips, long long mid) {

        long long actualtrips = 0;
        for(int i=0; i<time.size(); i++) {
            actualtrips += mid/time[i];
        }
        return actualtrips >= totalTrips;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {

        long long l = 1;
        long long r = 1LL * (*min_element(begin(time), end(time))) * (totalTrips);

        while(l < r) {
            long long mid = l+(r-l)/2;

            if(checkPoss(time, totalTrips, mid)) {
                r = mid;
            }
            else {
                l = mid+1;
            }
        }

        return l;
    }
};