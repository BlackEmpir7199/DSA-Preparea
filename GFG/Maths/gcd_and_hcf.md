# 🔢 **LCM and GCD Calculation**

## Problem Description

Given two integers \( a \) and \( b \), the task is to compute their Least Common Multiple (LCM) and Greatest Common Divisor (GCD). Return an array containing their LCM and GCD.

## 🎯 **Objective**

Write a function to calculate the LCM and GCD of two integers and return them as an array.

## ✨ **Example**

### Example 1:
```plaintext
Input: a = 5, b = 10
Output: [10, 5]
Explanation: The LCM of 5 and 10 is 10, and their GCD is 5.
```

### Example 2:
```plaintext
Input: a = 14, b = 8
Output: [56, 2]
Explanation: The LCM of 14 and 8 is 56, and their GCD is 2.
```

### Example 3:
```plaintext
Input: a = 1, b = 1
Output: [1, 1]
Explanation: The LCM of 1 and 1 is 1, and their GCD is 1.
```

## 🚀 **Approach**

### **GCD Calculation**

- Use the Euclidean algorithm to compute the GCD:
  - If \( b = 0 \), then \( \text{GCD}(a, b) = a \).
  - Otherwise, \( \text{GCD}(a, b) = \text{GCD}(b, a \% b) \).

### **LCM Calculation**

- The LCM of two numbers can be calculated using the formula:
  \[
  \text{LCM}(a, b) = \frac{a \times b}{\text{GCD}(a, b)}
  \]

### **Time Complexity**:
- The Euclidean algorithm for GCD runs in **O(log(min(a, b)))** time.
- The LCM calculation is **O(1)** once the GCD is known.

---

## 💡 **Code Implementation**

```cpp
class Solution {
public:
    int gcdfind(int a, int b) {
        if (b == 0) return a;
        return gcdfind(b, a % b);
    }

    vector<int> lcmAndGcd(int a, int b) {
        int gcd = gcdfind(a, b);
        int lcm = a * b / gcd;
        return {lcm, gcd};
    }
};
```

---

## 🔧 **Constraints**

- \( 1 \leq a, b \leq 10^9 \)

## 🌟 **Key Points**

- The Euclidean algorithm is efficient for calculating the GCD.
- The LCM is derived using the relationship between GCD and LCM.
- The solution handles large integers within the given constraints effectively.

---

## 🔗 **Related Topics**:
- Mathematical Algorithms
- Number Theory
- Euclidean Algorithm
- LCM and GCD Calculation