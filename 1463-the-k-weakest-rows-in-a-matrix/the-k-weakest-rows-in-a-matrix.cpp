class Solution {
public:
    int binarySearch(vector<int> &arr) {
        int st = 0;
        int end = arr.size()-1;
        int count = arr.size();

        while(st <= end) {
            int mid = st + (end-st)/2;

            if(arr[mid] == 0) {
                count = mid;
                end = mid-1;
            }
            else {
                st = mid+1;
            }
        }

        return count;
    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int>> vec;

        for(int i=0; i<mat.size(); i++) {
            int countSoldier = binarySearch(mat[i]);
            vec.push_back({countSoldier, i});
        }

        sort(vec.begin(), vec.end());
        vector<int> ans;
        for(int i=0; i<k; i++) {
            ans.push_back(vec[i].second);
        }
        return ans;
    }
};



