class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
    int n = matrix[0].size();

    // Step 1: Build heights
    for(int i = 1; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(matrix[i][j] != 0) {
                matrix[i][j] += matrix[i-1][j];
            }
        }
    }

    int ans = 0;

    // Step 2: For each row
    for(int i = 0; i < m; i++) {
        vector<int> temp = matrix[i];

        // Sort descending
        sort(temp.begin(), temp.end(), greater<int>());

        for(int j = 0; j < n; j++) {
            ans = max(ans, temp[j] * (j + 1));
        }
    }

    return ans;
    }
};