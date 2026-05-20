class Solution {
public:
    bool valid(vector<int>& piles, int h, int mid) {
        int maxEat = 0;
        for(int it : piles) {
            maxEat += (it + mid - 1)/mid;
        }
        return maxEat <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(begin(piles), end(piles));

        while(l < r) {
            int mid = l + (r-l)/2;
            if(valid(piles, h, mid)) {
                //go to left
                r = mid;
            }
            else {
                l = mid+1;
            }
        }

        return l;
    }
};