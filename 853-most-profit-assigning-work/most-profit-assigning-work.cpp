class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        priority_queue<pair<int, int>> maxHeap;

        for(int i=0; i<difficulty.size(); i++) {
            maxHeap.push({profit[i], difficulty[i]});
        }

        sort(worker.begin(), worker.end(), greater<int>());
        int ans = 0;
        int i = 0;
        while(i < worker.size() && !maxHeap.empty()) {
            if(maxHeap.top().second > worker[i]) {
                maxHeap.pop();
            }
            else {
                ans += maxHeap.top().first;
                i++;
            }
        }
        return ans;
    }
};