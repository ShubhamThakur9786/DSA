class Solution {
public:
    bool canReach(vector<int>& arr, int i) {
        if(i < 0 || i >= arr.size() || arr[i] < 0) {
            return false;
        }
        if(arr[i] == 0) {
            return true;
        }
        arr[i] *= -1;

        bool left = canReach(arr, i-arr[i]);
        bool right = canReach(arr, i+arr[i]);

        return left || right;
    }
};