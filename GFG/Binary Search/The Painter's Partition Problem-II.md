# 🎨 **The Painter's Partition Problem-II**

## Problem Description

Dilpreet wants to paint his dog's home that has `n` boards with different lengths. The length of the `i-th` board is given by `arr[i]` where `arr[]` is an array of `n` integers. He hired `k` painters for this work and each painter takes 1 unit time to paint 1 unit of the board.

Return the minimum time to get this job done if all painters start together with the constraint that any painter will only paint continuous boards, say boards numbered `[2, 3, 4]` or only board `[1]` or nothing but not boards `[2, 4, 5]`.

## 🎯 **Objective**

Write a function to determine the minimum time required to paint all the boards with `k` painters, given the constraints.

## ✨ **Examples**

### Example 1:
```plaintext
Input: arr[] = [5, 10, 30, 20, 15], k = 3
Output: 35
Explanation: The most optimal way will be:
- Painter 1 allocation: [5, 10]
- Painter 2 allocation: [30]
- Painter 3 allocation: [20, 15]
Job will be done when all painters finish i.e. at time = max(5+10, 30, 20+15) = 35
```

### Example 2:
```plaintext
Input: arr[] = [10, 20, 30, 40], k = 2
Output: 60
Explanation: The most optimal way to paint:
- Painter 1 allocation: [10, 20, 30]
- Painter 2 allocation: [40]
Job will be complete at time = 60
```

### Example 3:
```plaintext
Input: arr[] = [100, 200, 300, 400], k = 1
Output: 1000
Explanation: There is only one painter, so the painter must paint all boards sequentially. The total time taken will be the sum of all board lengths, i.e., 100 + 200 + 300 + 400 = 1000.
```

## 🚀 **Approach**

### **Binary Search with Greedy Allocation**

The algorithm uses binary search to find the minimum time required:

- **Initialization**:
  - Set the lower bound `low` to the maximum value in `arr`.
  - Set the upper bound `high` to the sum of all values in `arr`.

- **Binary Search**:
  - Calculate the midpoint `mid` of the current range.
  - Use a helper function `getCount` to check if it's possible to allocate the boards to `k` painters within `mid` time.
  - Adjust the search range based on the result of `getCount`.

- **Greedy Allocation**:
  - Traverse the `arr` array and allocate boards to painters while keeping track of the total time for each painter.
  - If the total time exceeds `mid`, allocate the remaining boards to the next painter.

### **Time Complexity**:
- The algorithm runs in **O(n log T)** time, where \( n \) is the length of the `arr` array and \( T \) is the range of possible times.

---

## 💡 **Code Implementation**

```cpp
class Solution {
    int getCount(vector<int>& arr, int mid) {
        long long sum = 0;
        int count = 1;
        for (int i : arr) {
            if (i + sum <= mid)
                sum += i;
            else {
                sum = i;
                count++;
            }
        }
        return count;
    }

public:
    int minTime(vector<int>& boards, int k) {
        int n = boards.size();
        int low = *max_element(boards.begin(), boards.end());
        int high = accumulate(boards.begin(), boards.end(), 0);
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int cnt = getCount(boards, mid);
            if (cnt > k)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return low;
    }
};
```

---

## 🔧 **Constraints**

- \( 1 \leq \text{arr.size()} \leq 10^5 \)
- \( 1 \leq \text{arr}[i] \leq 10^5 \)
- \( 1 \leq k \leq 10^5 \)

## 🌟 **Key Points**

- The algorithm efficiently finds the minimum time using binary search and a greedy allocation function.
- The solution handles the constraints well and ensures that the boards are accurately allocated to the painters.
- The use of binary search allows for an efficient determination of the minimum time required.

---

## 🔗 **Related Topics**:
- Array Manipulation
- Binary Search
- Greedy Algorithms