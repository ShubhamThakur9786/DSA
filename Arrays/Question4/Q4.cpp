// Move all negative elements to end
// Difficulty: Easy
// Given an unsorted array arr[ ] having both negative and positive integers. The task is to place all negative elements at the end of the array without changing the order of positive elements and negative elements.

// Note: Don't return any array, just in-place on the array.

// Examples:

// Input : arr[] = [1, -1, 3, 2, -7, -5, 11, 6 ]
// Output : [1, 3, 2, 11, 6, -1, -7, -5]
// Explanation: By doing operations we separated the integers without changing the order.
// Input : arr[] = [-5, 7, -3, -4, 9, 10, -1, 11]
// Output : [7, 9, 10, 11, -5, -3, -4, -1]

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void segregateElements(vector<int> &arr)
{
    vector<int> negNum;
    vector<int> posNum;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] < 0)
        {
            negNum.push_back(arr[i]);
        }
        else
        {
            posNum.push_back(arr[i]);
        }
    }

    for (int i = 0; i < negNum.size(); i++)
    {
        posNum.push_back(negNum[i]);
    }

    for (int i = 0; i < arr.size(); i++)
    {
        arr[i] = posNum[i];
    }
}

int main()
{
    vector<int> arr = {1, 2, 3, -1, -2, -4};
    segregateElements(arr);
}