// Reverse an Array
// Difficulty: Easy
// You are given an array of integers arr[]. You have to reverse the given array.

// Note: Modify the array in place.

// Examples:

// Input: arr = [1, 4, 3, 2, 6, 5]
// Output: [5, 6, 2, 3, 4, 1]
// Explanation: The elements of the array are [1, 4, 3, 2, 6, 5]. After reversing the array, the first element goes to the last position, the second element goes to the second last position and so on. Hence, the answer is [5, 6, 2, 3, 4, 1].
// Input: arr = [4, 5, 2]
// Output: [2, 5, 4]
// Explanation: The elements of the array are [4, 5, 2]. The reversed array will be [2, 5, 4].

#include <vector>
#include <algorithm>
#include <iostream>
#include <stdio.h>
using namespace std;

class Solution
{
public:
    void reverseArray(vector<int> &arr)
    {
        int st = 0;
        int end = arr.size() - 1;

        while (st <= end)
        {
            swap(arr[st], arr[end]);
            st++;
            end--;
        }
    }
};

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    Solution s;
    s.reverseArray(arr);

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
}