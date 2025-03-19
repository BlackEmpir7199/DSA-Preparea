# 📚 **Allocate Minimum Pages**

## Problem Description

You are given an array `arr[]` of integers, where each element `arr[i]` represents the number of pages in the \( i \)-th book. You also have an integer \( k \) representing the number of students. Your task is to allocate books to each student such that:

- Each student receives at least one book.
- Each student is assigned a contiguous sequence of books.
- No book is assigned to more than one student.
- The objective is to minimize the maximum number of pages assigned to any student.

Return `-1` if a valid assignment is not possible.

## 🎯 **Objective**

Write a function to determine the minimum possible maximum number of pages that can be allocated to any student.

## ✨ **Example**

### Example 1:
```plaintext
Input: arr[] = [12, 34, 67, 90], k = 2
Output: 113
Explanation: Possible allocations:
- [12] and [34, 67, 90] with maximum pages = 191
- [12, 34] and [67, 90] with maximum pages = 157
- [12, 34, 67] and [90] with maximum pages = 113
The minimum of these cases is 113.
```

### Example 2:
```plaintext
Input: arr[] = [15, 17, 20], k = 5
Output: -1
Explanation: Allocation is not possible as there are fewer books than students.
```

### Example 3:
```plaintext
Input: arr[] = [22, 23, 67], k = 1
Output: 112
Explanation: All books must be allocated to one student, resulting in 112 pages.
```

## 🚀 **Approach**

### **Binary Search with Feasibility Check**

The algorithm uses binary search to find the minimum possible maximum number of pages:

- **Initialization**:
  - Set the lower bound `low` as the maximum number of pages in a single book.
  - Set the upper bound `high` as the sum of all pages.

- **Binary Search**:
  - Calculate the midpoint `mid` of the current range.
  - Use a helper function `getCount` to determine if it's possible to allocate books such that no student receives more than `mid` pages.
  - Adjust the search range based on the feasibility check.

- **Feasibility Check**:
  - Traverse the array and allocate books to students while keeping track of the total pages allocated to the current student.
  - If the total exceeds `mid`, allocate the remaining books to the next student and increment the student count.

### **Time Complexity**:
- The algorithm runs in **O(n log(sum(arr)))** time, where \( n \) is the number of books.

---

## 💡 **Code Implementation**

```cpp
#include <bits/stdc++.h>

int getCount(int n, std::vector<int>& arr) {
    long long sum = 0;
    int count = 1;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] + sum <= n)
            sum += arr[i];
        else {
            sum = arr[i];
            count++;
        }
    }
    return count;
}

int findPages(std::vector<int>& arr, int n, int m) {
    if (m > n) return -1;
    int low = *std::max_element(arr.begin(), arr.end());
    int high = std::accumulate(arr.begin(), arr.end(), 0);
    while (high >= low) {
        int mid = (low + high) / 2;
        int stdcnt = getCount(mid, arr);
        if (stdcnt > m)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}
```

---

## 🔧 **Constraints**

- \( 1 \leq \text{arr.size()} \leq 10^6 \)
- \( 1 \leq \text{arr}[i] \leq 10^3 \)
- \( 1 \leq k \leq 10^3 \)

## 🌟 **Key Points**

- The binary search efficiently narrows down the minimum possible maximum pages.
- The feasibility check ensures that the allocation is valid for the current midpoint.
- The solution handles large inputs effectively within the given constraints.

---

## 🔗 **Related Topics**:
- Binary Search
- Array Manipulation
- Greedy Al