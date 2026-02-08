// Kth Smallest
// Difficulty: Medium

// Given an integer array arr[] and an integer k, your task is to find and return the kth smallest element in the given array.

// Note: The kth smallest element is determined based on the sorted order of the array.

// Examples :

// Input: arr[] = [10, 5, 4, 3, 48, 6, 2, 33, 53, 10], k = 4
// Output: 5
// Explanation: 4th smallest element in the given array is 5.
// Input: arr[] = [7, 10, 4, 3, 20, 15], k = 3
// Output: 7
// Explanation: 3rd smallest element in the given array is 7.

// Brute Force
#include <vector>
#include <bits/stdc++.h>
using namespace std;

// int kthSmallest(vector<int> &arr, int k)
// {
//     // code here
//     // brute force
//     sort(arr.begin(), arr.end());

//     return arr[k - 1];
// }

int kthSmallest(vector<int> &arr, int k)
{
    priority_queue<int> maxheap;
    for (int i = 0; i < arr.size(); i++)
    {
        maxheap.push(arr[i]);
        if (maxheap.size() > k)
        {
            maxheap.pop();
        }
    }

    return maxheap.top();
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 3;
    cout << kthSmallest(arr, k);
}