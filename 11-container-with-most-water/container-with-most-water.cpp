class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i = 0;
        int j = height.size()-1;

        int maxi = INT_MIN;

        while(i < j) {
            int waterStore = min(height[i], height[j]);
            int area = waterStore * (j-i);

            maxi = max(maxi, area);

            if(height[i] < height[j]) {
                i++;
            }
            else {
                j--;
            }
        }
        return maxi;
    }
};