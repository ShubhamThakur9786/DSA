// Min and Max in Array
// Difficulty: Basic

// Given an array arr[]. Your task is to find the minimum and maximum elements in the array.

// Examples:

// Input: arr[] = [1, 4, 3, 5, 8, 6]
// Output: [1, 8]
// Explanation: minimum and maximum elements of array are 1 and 8.
// Input: arr[] = [12, 3, 15, 7, 9]
// Output: [3, 15]
// Explanation: minimum and maximum element of array are 3 and 15.

#include <vector>
#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <climits>
using namespace std;

class Solution
{
public:
    vector<int> getMinMax(vector<int> &arr)
    {
        // code here
        vector<int> ans;
        int mini = INT_MAX;
        int maxi = INT_MIN;

        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] > maxi)
            {
                maxi = arr[i];
            }
            if (arr[i] < mini)
            {
                mini = arr[i];
            }
        }

        ans.push_back(mini);
        ans.push_back(maxi);
        return ans;
    }
};

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    Solution s;
    vector<int> ans = s.getMinMax(arr);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}