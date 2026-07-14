bool sortBySecond(pair<int, int>& a, pair<int, int>& b) {
    if (a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int>> vec;  //row, countofone

        for(int i=0; i<mat.size(); i++) {
            int countOne = 0;
            for(int j=0; j<mat[0].size(); j++) {
                if(mat[i][j] == 0) {
                    break;
                }
                else {
                    countOne++;
                }
            }
            vec.push_back({i, countOne});
        }

        sort(vec.begin(), vec.end(), sortBySecond);

        vector<int> ans;
        for(int i=0; i<k; i++) {
            ans.push_back(vec[i].first);
        }
        return ans;
    }
};