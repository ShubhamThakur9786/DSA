class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int l = 0;
        int r = n-1;

        while(l <= r) {
            int mid = l+(r-l)/2;
            int missing_no_till_mid = arr[mid]-(mid+1);

            if(missing_no_till_mid < k) {
                l = mid+1;
            }            
            else {
                r = mid-1;
            }
        }

        return l + k;
    }
};