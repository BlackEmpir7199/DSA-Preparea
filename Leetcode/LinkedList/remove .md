# 🔗 **Remove Linked List Elements**

## Problem Description

Given the head of a linked list and an integer `val`, remove all the nodes of the linked list that have `Node.val == val`, and return the new head.

## 🎯 **Objective**

Write a function to remove all nodes with the specified value from the linked list and return the new head of the list.

## ✨ **Examples**

### Example 1:
```plaintext
Input: head = [1, 2, 6, 3, 4, 5, 6], val = 6
Output: [1, 2, 3, 4, 5]
```

### Example 2:
```plaintext
Input: head = [], val = 1
Output: []
```

### Example 3:
```plaintext
Input: head = [7, 7, 7, 7], val = 7
Output: []
```

## 🚀 **Approach**

### **Two-Pointer Technique**

The algorithm uses a two-pointer technique to efficiently remove the nodes with the specified value:

- **Initialization**:
  - Use a pointer `head` to traverse the linked list and remove leading nodes with the value `val`.
  - Use a pointer `remover` to traverse the rest of the list and remove nodes with the value `val`.

- **Removing Leading Nodes**:
  - Traverse the list using the `head` pointer and remove all leading nodes that have the value `val`.

- **Removing Other Nodes**:
  - Use the `remover` pointer to traverse the list.
  - If the next node has the value `val`, skip it by updating the `next` pointer of the current node.
  - Otherwise, move the `remover` pointer to the next node.

### **Time Complexity**:
- The algorithm runs in **O(n)** time, where \( n \) is the number of nodes in the linked list.

---

## 💡 **Code Implementation**

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        // Remove leading nodes with the value `val`
        while (head && head->val == val) {
            head = head->next;
        }
        // Use a pointer to traverse the list and remove nodes with the value `val`
        ListNode* remover = head;
        while (remover && remover->next) {
            if (remover->next->val == val) {
                remover->next = remover->next->next;
            } else {
                remover = remover->next;
            }
        }
        return head;
    }
};
```

---

## 🔧 **Constraints**

- The number of nodes in the list is in the range `[0, 10^4]`.
- \( 1 \leq \text{Node.val} \leq 50 \)
- \( 0 \leq \text{val} \leq 50 \)

## 🌟 **Key Points**

- The algorithm efficiently removes nodes with the specified value using a two-pointer technique.
- The solution handles the constraints well and ensures that all nodes with the specified value are removed.
- The use of two pointers allows for an efficient traversal and modification of the linked list.

---

## 🔗 **Related Topics**:
- Linked List Manipulation
- Two-Pointer Technique
- Algorithm Optimization