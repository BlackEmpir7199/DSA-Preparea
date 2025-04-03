# 🔢 **Longest Subarray with Sum K**

## Problem Description

Given an array `arr` of integers and an integer `k`, find the length of the longest subarray where the sum of its elements equals `k`. If no such subarray exists, return `0`.

## 🎯 **Objective**

Write a function to determine the length of the longest subarray with a sum equal to `k`.

## ✨ **Example**

### Example 1:
```plaintext
Input: arr = [10, 5, 2, 7, 1, -10], k = 15
Output: 6
Explanation: The longest subarray with a sum of 15 is [10, 5, 2, 7, 1, -10].
```

### Example 2:
```plaintext
Input: arr = [-5, 8, -14, 2, 4, 12], k = -5
Output: 5
Explanation: The longest subarray with a sum of -5 is [-5, 8, -14, 2, 4].
```

### Example 3:
```plaintext
Input: arr = [10, -10, 20, 30], k = 5
Output: 0
Explanation: There is no subarray with a sum of 5.
```

## 🚀 **Approach**

### **Hash Map for Sum Tracking**

The algorithm uses a hash map to efficiently track the sum of elements and find the longest subarray:

- **Initialization**:
  - Use a hash map to store the first occurrence of each sum encountered.

- **Sum Tracking**:
  - Traverse the array while maintaining a running sum of elements.
  - For each element, check if the running sum equals `k`, which indicates a valid subarray ending at the current index.
  - Calculate the remainder `rem = sum - k`. If `rem` has been seen before, it indicates a subarray with sum `k` exists between the previous index of `rem` and the current index.

- **Update Maximum Length**:
  - Update the maximum length of the subarray found.

### **Time Complexity**:
- The algorithm runs in **O(n)** time, where \( n \) is the length of the array.

### **Space Complexity**:
- The algorithm uses **O(n)** extra space for the hash map.

---

## 💡 **Code Implementation**

```cpp
class Solution {
public:
    int longestSubarray(vector<int>& arr, int k) {
        unordered_map<long long, int> mpp;
        int n = arr.size();
        int maxlen = 0;
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += arr[i];
            if (sum == k)
                maxlen = i + 1;
            long long rem = sum - k;
            if (mpp.find(rem) != mpp.end())
                maxlen = max(maxlen, i - mpp[rem]);
            if (mpp.find(sum) == mpp.end())
                mpp[sum] = i;
        }
        return maxlen;
    }
};
```

---

## 🔧 **Constraints**

- \( 1 \leq \text{arr.size()} \leq 10^5 \)
- \( -10^4 \leq \text{arr}[i] \leq 10^4 \)
- \( -10^9 \leq k \leq 10^9 \)

## 🌟 **Key Points**

- The algorithm efficiently finds the longest subarray with a sum equal to `k` using a hash map to track sums.
- The solution handles large inputs effectively within the given constraints.
- The use of a hash map allows for a linear time complexity solution.

---

## 🔗 **Related Topics**:
- Hash Table
- Array Manipulation
- Prefix Sum