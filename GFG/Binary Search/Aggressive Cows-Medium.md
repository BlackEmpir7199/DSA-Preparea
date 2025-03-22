# 🐄 **Aggressive Cows**

## Problem Description

You are given an array `stalls[]` with unique elements, representing the positions of stalls. You also have an integer `k`, which denotes the number of aggressive cows. Your task is to assign stalls to `k` cows such that the minimum distance between any two cows is maximized.

## 🎯 **Objective**

Write a function to determine the maximum possible minimum distance between any two cows when placing `k` cows in the given stalls.

## ✨ **Example**

### Example 1:
```plaintext
Input: stalls = [1, 2, 4, 8, 9], k = 3
Output: 3
Explanation: Place the first cow at stalls[0], the second cow at stalls[2], and the third cow at stalls[3]. The minimum distance between cows is 3, which is the largest possible.
```

### Example 2:
```plaintext
Input: stalls = [10, 1, 2, 7, 5], k = 3
Output: 4
Explanation: Place the first cow at stalls[0], the second cow at stalls[1], and the third cow at stalls[4]. The minimum distance between cows is 4, which is the largest possible.
```

### Example 3:
```plaintext
Input: stalls = [2, 12, 11, 3, 26, 7], k = 5
Output: 1
Explanation: Each cow can be placed in any of the stalls since the number of stalls equals the number of cows. The minimum distance between cows is 1, which is the largest possible.
```

## 🚀 **Approach**

### **Binary Search with Feasibility Check**

The algorithm uses binary search to find the maximum possible minimum distance:

- **Initialization**:
  - Sort the `stalls` array to facilitate binary search.
  - Set the lower bound `low` to 1 (the minimum possible distance).
  - Set the upper bound `high` to the difference between the last and first stall (the maximum possible distance).

- **Binary Search**:
  - Calculate the midpoint `mid` of the current range.
  - Use a helper function `canCows` to check if it's possible to place `k` cows with a minimum distance of `mid`.
  - Adjust the search range based on the feasibility check.

- **Feasibility Check**:
  - Traverse the array and place cows while maintaining the minimum distance constraint `mid`.
  - Count the number of cows placed. If the count is at least `k`, it means the distance `mid` is feasible.

### **Time Complexity**:
- The algorithm runs in **O(n log(max(stalls)))** time, where \( n \) is the number of stalls.

---

## 💡 **Code Implementation**

```cpp
class Solution {
    bool canCows(int mid, vector<int>& arr, int k) {
        int cnt = 1, prevCow = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] - prevCow >= mid) {
                cnt++;
                prevCow = arr[i];
            }
            if (cnt >= k) return true;
        }
        return false;
    }

public:
    int aggressiveCows(vector<int>& stalls, int k) {
        sort(stalls.begin(), stalls.end());
        int n = stalls.size();
        int low = 1, high = stalls[n - 1] - stalls[0];
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canCows(mid, stalls, k))
                low = mid + 1;
            else
                high = mid - 1;
        }
        return high;
    }
};
```

---

## 🔧 **Constraints**

- \( 2 \leq \text{stalls.size()} \leq 10^6 \)
- \( 0 \leq \text{stalls}[i] \leq 10^8 \)
- \( 2 \leq k \leq \text{stalls.size()} \)

## 🌟 **Key Points**

- The binary search efficiently narrows down the maximum possible minimum distance.
- The feasibility check ensures that the cows can be placed with the required minimum distance.
- The solution handles large inputs effectively within the given constraints.

---

## 🔗 **Related Topics**:
- Binary Search
- Array Manipulation
- Greedy Algorithm