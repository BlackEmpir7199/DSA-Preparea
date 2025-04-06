# 🔄 **Count Inversions**

## Problem Description

Given an array of integers `arr[]`, find the Inversion Count in the array. Two elements `arr[i]` and `arr[j]` form an inversion if `arr[i] > arr[j]` and `i < j`.

The Inversion Count indicates how far (or close) the array is from being sorted. If the array is already sorted, the inversion count is 0. If an array is sorted in reverse order, the inversion count is the maximum.

## 🎯 **Objective**

Write a function to count the number of inversions in the given array.

## ✨ **Examples**

### Example 1:
```plaintext
Input: arr[] = [2, 4, 1, 3, 5]
Output: 3
Explanation: The sequence 2, 4, 1, 3, 5 has three inversions: (2, 1), (4, 1), (4, 3).
```

### Example 2:
```plaintext
Input: arr[] = [2, 3, 4, 5, 6]
Output: 0
Explanation: As the sequence is already sorted, there is no inversion count.
```

### Example 3:
```plaintext
Input: arr[] = [10, 10, 10]
Output: 0
Explanation: As all the elements of the array are the same, there is no inversion count.
```

## 🚀 **Approach**

### **Merge Sort with Counting**

The algorithm uses a modified merge sort to count the inversions efficiently:

- **Merge Sort**:
  - Divide the array into two halves.
  - Recursively count the inversions in each half.
  - Count the inversions that span across the two halves.

- **Counting Inversions**:
  - For each element in the left half, count how many elements in the right half are smaller.

- **Merging**:
  - Merge the two halves back together in sorted order.

### **Time Complexity**:
- The algorithm runs in **O(n log n)** time, where \( n \) is the length of the array.

---

## 💡 **Code Implementation**

```cpp
class Solution {
    int merge(vector<int> &arr, int low, int mid, int high) {
        vector<int> temp;
        int right = mid + 1;
        int left = low;
        int cnt = 0;
        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right])
                temp.push_back(arr[left++]);
            else {
                temp.push_back(arr[right++]);
                cnt += (mid - left + 1);
            }
        }
        while (left <= mid) {
            temp.push_back(arr[left++]);
        }
        while (right <= high) {
            temp.push_back(arr[right++]);
        }
        for (int i = low; i <= high; i++)
            arr[i] = temp[i - low];
        return cnt;
    }

    int mergeSort(vector<int> &arr, int low, int high) {
        int cnt = 0;
        if (low >= high) return cnt;
        int mid = low + (high - low) / 2;
        cnt += mergeSort(arr, low, mid);
        cnt += mergeSort(arr, mid + 1, high);
        cnt += merge(arr, low, mid, high);
        return cnt;
    }

public:
    // Function to count inversions in the array.
    int inversionCount(vector<int> &arr) {
        return mergeSort(arr, 0, arr.size() - 1);
    }
};
```

---

## 🔧 **Constraints**

- \( 1 \leq \text{arr.size()} \leq 10^5 \)
- \( 1 \leq \text{arr}[i] \leq 10^4 \)

## 🌟 **Key Points**

- The algorithm efficiently counts the inversions using a modified merge sort.
- The solution handles the constraints well and ensures that the inversions are accurately counted.
- The use of merge sort allows for a straightforward counting of inversions while maintaining the sorted order.

---

## 🔗 **Related Topics**:
- Array Manipulation
- Merge Sort
- Counting Inversions