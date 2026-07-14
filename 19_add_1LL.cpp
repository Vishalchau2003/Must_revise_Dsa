// #include <bits/stdc++.h>
// using namespace std;

// /*
// =========================================================
// Approach 1: Iterative (Reverse the Linked List)
// =========================================================

// Algorithm:
// 1. Reverse the linked list.
// 2. Add 1 starting from the first node.
// 3. Propagate carry if required.
// 4. Reverse the list again.
// 5. If carry still exists, create a new head node.

// Time Complexity: O(3N) ≈ O(N)
// Space Complexity: O(1)

// =========================================================
// */

// class Solution {
// public:

//     Node* reverse(Node* head) {
//         Node* prev = nullptr;
//         Node* curr = head;

//         while (curr) {
//             Node* next = curr->next;
//             curr->next = prev;
//             prev = curr;
//             curr = next;
//         }

//         return prev;
//     }

//     Node* addOne(Node* head) {

//         // Step 1: Reverse the linked list
//         head = reverse(head);

//         Node* temp = head;
//         int carry = 1;

//         // Step 2: Add one
//         while (temp) {

//             temp->data += carry;

//             // No carry generated
//             if (temp->data < 10) {
//                 carry = 0;
//                 break;
//             }

//             // Carry generated
//             temp->data = 0;
//             carry = 1;

//             temp = temp->next;
//         }

//         // Step 3: Reverse back
//         head = reverse(head);

//         // Step 4: If carry still exists
//         if (carry) {
//             Node* newNode = new Node(1);
//             newNode->next = head;
//             return newNode;
//         }

//         return head;
//     }
// };

// /*
// =========================================================
// Approach 2: Recursive
// =========================================================

// Algorithm:
// 1. Traverse till the last node using recursion.
// 2. Return carry while backtracking.
// 3. Update every node.
// 4. If carry remains after head, create a new node.

// Time Complexity: O(N)
// Space Complexity: O(N)  (Recursion Stack)

// =========================================================
// */

// class Solution {
// public:

//     int helper(Node* temp) {

//         // Base Case
//         if (temp == nullptr)
//             return 1;

//         // Recursive Call
//         int carry = helper(temp->next);

//         // Add carry to current node
//         temp->data += carry;

//         // No carry generated
//         if (temp->data < 10)
//             return 0;

//         // Carry generated
//         temp->data = 0;
//         return 1;
//     }

//     Node* addOne(Node* head) {

//         int carry = helper(head);

//         // If carry still exists
//         if (carry) {
//             Node* newNode = new Node(1);
//             newNode->next = head;
//             return newNode;
//         }

//         return head;
//     }
// };