class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<int> ans;

        for(int i=0; i<intervals.size(); i++) {
            int currVal = intervals[i][1];
            int miniVal = -1;
            for(int j=0; j<intervals.size(); j++) {
                if(intervals[j][0] >= currVal) {
                    //miniVal se bhi choti koi value mili jo badi h currVal se
                    if(miniVal == -1 || intervals[j][0] < intervals[miniVal][0]) {
                        miniVal = j;
                    }
                }
            }
            ans.push_back(miniVal);
        }
        return ans;
    }
};