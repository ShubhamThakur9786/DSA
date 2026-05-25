class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size();
        vector<int> temp;
        int i=0;   
        while(i < arr.size() && temp.size() < n) {
            temp.push_back(arr[i]);

            if(arr[i] == 0 && temp.size() < n) {
                temp.push_back(arr[i]);
            }
            i++;
        }
        arr = temp;
    }
};