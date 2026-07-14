#include <bits/stdc++.h>
using namespace std;

/*
=========================================================
LeetCode 2: Add Two Numbers
=========================================================

Problem:
Two non-empty linked lists represent two non-negative integers.
The digits are stored in reverse order, and each node contains
a single digit. Add the two numbers and return the sum as a
linked list.

Example:
l1 = 2 -> 4 -> 3
l2 = 5 -> 6 -> 4

Represents:
342 + 465 = 807

Output:
7 -> 0 -> 8

---------------------------------------------------------
Algorithm
---------------------------------------------------------
1. Create a dummy node.
2. Traverse both linked lists simultaneously.
3. Add corresponding digits along with the carry.
4. Create a new node containing (sum % 10).
5. Update carry = sum / 10.
6. Continue until both lists and carry are exhausted.

Time Complexity : O(max(N, M))
Space Complexity: O(max(N, M))   // Output linked list

=========================================================
*/

// class Solution {
// public:

//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

//         // Dummy node to simplify insertion
//         ListNode* dummyNode = new ListNode(-1);
//         ListNode* curr = dummyNode;

//         ListNode* temp1 = l1;
//         ListNode* temp2 = l2;

//         int carry = 0;

//         while (temp1 != nullptr || temp2 != nullptr || carry != 0) {

//             // Start with previous carry
//             int sum = carry;

//             // Add value from first list
//             if (temp1 != nullptr) {
//                 sum += temp1->val;
//                 temp1 = temp1->next;
//             }

//             // Add value from second list
//             if (temp2 != nullptr) {
//                 sum += temp2->val;
//                 temp2 = temp2->next;
//             }

//             // Update carry
//             carry = sum / 10;

//             // Create node for current digit
//             curr->next = new ListNode(sum % 10);
//             curr = curr->next;
//         }

//         return dummyNode->next;
//     }
// };