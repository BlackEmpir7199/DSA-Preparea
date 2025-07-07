#include <bits/stdc++.h>

using namespace std;

bool isValid(long long totalCandies, long long mid, long long k)
{
    totalCandies /= mid;
    return totalCandies >= k;
}

int maximumCandies(vector<int> &candies, long long k)
{

    int left = 1;
    int right = INT_MAX;
    int totalCandies = 0;

    for (int i : candies)
    {
        totalCandies += i;
        right = min(i, right);
    }

    if(totalCandies<k)  return 0;

    while (right > left+1)
    {
        long long mid = left + (right - left) / 2;
        if (isValid(totalCandies, mid, k))
        {
            left = mid;
        }
        else
        {
            right = mid;
        }
    }

    return right;
}

int lowerBound(vector<int> &arr, int target)
{
    int low = 0, high = arr.size() - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] >= target)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}

int upperBound(vector<int> &arr, int target)
{
    int low = 0, high = arr.size() - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] > target)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}

int main()
{
    vector<int> arr = {5,8,6};
    cout << maximumCandies(arr, 3);
    return 0;
}