class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> ans;

        int prefixXor = 0;
        vector<int> temp;
        for(int i=0; i<arr.size(); i++) {
            prefixXor = prefixXor ^ arr[i];
            temp.push_back(prefixXor);
        }

        for(int i=0; i<queries.size(); i++) {
            vector<int> a = queries[i];
            int st = a[0];
            int end = a[1];
            int result = 0;
            if(st-1 < 0) {
                result = temp[end];
            }
            else {
                result = temp[st-1]^temp[end];
            }
            ans.push_back(result);
        }
        return ans;
    }
};