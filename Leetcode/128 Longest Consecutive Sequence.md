# 📌 **128. Longest Consecutive Sequence**  
**Leetcode Link:** [Longest Consecutive Sequence](https://leetcode.com/problems/longest-consecutive-sequence/)  

---

## 🎯 **Problem Statement**  
You are given an **integer array `A`** of size `N`.  

**Objective:**  
- Find the **length of the longest consecutive sequence** in the array.  
- The sequence **can be reordered** to form consecutive elements.  

---

## 🔹 **Example 1**
```plaintext
Input: A = [5, 8, 3, 2, 1, 4], N = 6
Output: 5

Explanation:
- The longest consecutive sequence is: **[1, 2, 3, 4, 5]**
- The length of the sequence is **5**.
```

---

## 🔹 **Example 2**
```plaintext
Input: A = [100, 4, 200, 1, 3, 2]
Output: 4

Explanation:
- The longest consecutive sequence is **[1, 2, 3, 4]**
- Length = **4**.
```

---

## 🚀 **Approach: HashSet Optimization**
### **Intuition**
- The brute force approach would involve sorting, but that takes **O(N log N)** time.
- A **HashSet** helps us check the presence of an element in **O(1)** time.
- The key optimization is to **only start counting when we find the start of a sequence** (i.e., `num - 1` is not present).

### **Steps**
1. Insert all elements into a **HashSet** to allow **O(1) lookup**.
2. Iterate through each number:
   - If `num - 1` **does not exist** in the set, it means `num` is the start of a new sequence.
   - Expand the sequence by checking `num + 1`, `num + 2`, etc.
   - Track the **maximum length** encountered.
3. Return the longest sequence length.

---

## 💡 **Code Implementation**

### ✅ **Java Implementation**
```java
import java.util.HashSet;

public class Solution {
    public static int longestSuccessiveElements(int[] a) {
        HashSet<Integer> set = new HashSet<>();
        
        // Insert all elements into a HashSet
        for (int num : a) {
            set.add(num);
        }
        
        int longest = 0;

        for (int num : a) {
            // Only check sequences starting with num (num - 1 should not exist)
            if (!set.contains(num - 1)) {
                int currentNum = num;
                int count = 1;

                // Expand sequence
                while (set.contains(currentNum + 1)) {
                    currentNum++;
                    count++;
                }
                
                longest = Math.max(longest, count);
            }
        }
        
        return longest;
    }
}
```

---

## 🔥 **Complexity Analysis**
| **Approach**       | **Time Complexity** | **Space Complexity** | **Reasoning** |
|--------------------|--------------------|---------------------|--------------|
| **Sorting + DP**  | **O(N log N)** | **O(1)** | Sorting takes O(N log N), then linear pass |
| **HashSet (Optimal)** | **O(N)** | **O(N)** | HashSet lookup is O(1), each element is processed once |

---

## 🌟 **Key Takeaways**
- **Avoid sorting** when an **O(N)** approach is possible.
- **HashSet** allows **O(1)** lookup to efficiently find consecutive sequences.
- **Start only at sequence beginnings (`num - 1` should not exist)** to minimize redundant calculations.

