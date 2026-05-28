class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int sum = 0;
        int n = arr.size();

        for(int i=0; i<arr.size(); i++) {
            int left = i+1;
            int right = n-i;

            int totalSubarray = left*right;
            int oddLen = (totalSubarray+1)/2;
            sum += arr[i]*oddLen;
        }
        return sum;
    }
};