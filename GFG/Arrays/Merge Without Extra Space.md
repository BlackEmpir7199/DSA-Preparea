# 🔁 **Merge Without Extra Space**

## Problem Description

Given two sorted arrays `a[]` and `b[]` of sizes `n` and `m` respectively, the task is to merge them in sorted order without using any extra space. Modify `a[]` so that it contains the first `n` elements and modify `b[]` so that it contains the last `m` elements.

## 🎯 **Objective**

Write a function to merge two sorted arrays in-place without using any extra space.

## ✨ **Examples**

### Example 1:
```plaintext
Input: a[] = [2, 4, 7, 10], b[] = [2, 3]
Output:
2 2 3 4
7 10
Explanation: After merging the two non-decreasing arrays, we get 2 2 3 4 7 10.
```

### Example 2:
```plaintext
Input: a[] = [1, 5, 9, 10, 15, 20], b[] = [2, 3, 8, 13]
Output:
1 2 3 5 8 9
10 13 15 20
Explanation: After merging two sorted arrays, we get 1 2 3 5 8 9 10 13 15 20.
```

### Example 3:
```plaintext
Input: a[] = [0, 1], b[] = [2, 3]
Output:
0 1
2 3
Explanation: After merging two sorted arrays, we get 0 1 2 3.
```

## 🚀 **Approach**

### **In-Place Merging**

The algorithm merges the two arrays in-place using the following steps:

- **Initialization**:
  - Start with the last element of `a[]` and the first element of `b[]`.

- **Swapping Elements**:
  - Compare the last element of `a[]` with the first element of `b[]`.
  - If the last element of `a[]` is greater than the first element of `b[]`, swap them.
  - Move to the next element in `a[]` and `b[]` respectively.

- **Sorting**:
  - After swapping the necessary elements, sort both arrays to ensure they are in non-decreasing order.

### **Time Complexity**:
- The algorithm runs in **O(n log n + m log m)** time due to the sorting step, where `n` and `m` are the sizes of the arrays `a` and `b` respectively.

---

## 💡 **Code Implementation**

```cpp
class Solution {
public:
    void mergeArrays(vector<int>& a, vector<int>& b) {
        int n = a.size(), m = b.size();
        int i = n - 1, j = 0;
        while (i >= 0 && j < m) {
            if (a[i] > b[j]) {
                swap(a[i], b[j]);
                i--;
                j++;
            } else {
                break;
            }
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
    }
};
```

---

## 🔧 **Constraints**

- \( 1 \leq \text{a.size()}, \text{b.size()} \leq 10^5 \)
- \( 0 \leq \text{a}[i], \text{b}[i] \leq 10^7 \)

## 🌟 **Key Points**

- The algorithm efficiently merges two sorted arrays in-place without using any extra space.
- The solution handles the constraints well and ensures that the arrays are accurately merged and sorted.
- The use of swapping and sorting allows for a straightforward in-place merging of the arrays.

---

## 🔗 **Related Topics**:
- Array Manipulation
- In-Place Algorithms
- Sorting