# 🔢 **Missing and Repeating Numbers**

## Problem Description

Given an unsorted array `arr` of positive integers, where one number `a` from the set `[1, 2, ..., n]` is missing and one number `b` occurs twice, find the numbers `a` and `b`.

## 🎯 **Objective**

Write a function to determine the missing number and the repeating number in the array.

## ✨ **Example**

### Example 1:
```plaintext
Input: arr = [2, 2]
Output: [2, 1]
Explanation: The repeating number is 2 and the missing number is 1.
```

### Example 2:
```plaintext
Input: arr = [1, 3, 3]
Output: [3, 2]
Explanation: The repeating number is 3 and the missing number is 2.
```

### Example 3:
```plaintext
Input: arr = [4, 3, 6, 2, 1, 1]
Output: [1, 5]
Explanation: The repeating number is 1 and the missing number is 5.
```

## 🚀 **Approach**

### **Mathematical Calculation**

The algorithm uses mathematical properties to find the missing and repeating numbers:

- **Initialization**:
  - Calculate the expected sum `s1` of the first `n` natural numbers using the formula \( \frac{n(n+1)}{2} \).
  - Calculate the expected sum of squares `s2` of the first `n` natural numbers using the formula \( \frac{n(n+1)(2n+1)}{6} \).

- **Sum Calculation**:
  - Compute the actual sum `ms1` and the sum of squares `ms2` of the elements in the array.

- **Difference Calculation**:
  - The difference between the expected sum and the actual sum gives the difference between the missing and repeating numbers.
  - The difference between the expected sum of squares and the actual sum of squares, divided by the difference in sums, gives the sum of the missing and repeating numbers.

- **Finding Numbers**:
  - Use the sum and difference of the missing and repeating numbers to find their values.

### **Time Complexity**:
- The algorithm runs in **O(n)** time.

### **Space Complexity**:
- The algorithm uses **O(1)** extra space.

---

## 💡 **Code Implementation**

```cpp
class Solution {
public:
    vector<int> findTwoElement(vector<int>& arr) {
        long long n = arr.size();
        long long s1 = n * (n + 1) / 2;
        long long s2 = n * (n + 1) * (2 * n + 1) / 6;
        long long ms1 = 0, ms2 = 0;
        for (int i = 0; i < n; i++) {
            ms1 += arr[i];
            ms2 += (long long)arr[i] * (long long)arr[i];
        }
        long long val1 = s1 - ms1;
        long long val2 = s2 - ms2;
        val2 = val2 / val1;
        long long x = (val2 + val1) / 2;
        long long y = x - val1;
        return {x, y};
    }
};
```

---

## 🔧 **Constraints**

- \( 2 \leq \text{arr.size()} \leq 10^6 \)
- \( 1 \leq \text{arr}[i] \leq \text{arr.size()} \)

## 🌟 **Key Points**

- The algorithm efficiently finds the missing and repeating numbers using mathematical properties.
- The solution handles large inputs effectively within the given constraints.
- The use of sum and difference calculations allows for a linear time complexity solution.

---

## 🔗 **Related Topics**:
- Mathematical Algorithms
- Array Manipulation
- Sum and Difference Calculations