class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int sumA = 0;
        int sumB = 0;

        for(auto it : aliceSizes) sumA += it;
        for(auto it : bobSizes) sumB += it;

        int diff = (sumA-sumB)/2;

        unordered_set<int> st(bobSizes.begin(), bobSizes.end());

        for(auto a : aliceSizes) {
            int b = a - diff;
            if(st.count(b)) {
                return {a, b};
            }
        }
        return {};
    }
};