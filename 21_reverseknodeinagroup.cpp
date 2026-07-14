#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};

class Solution {
public:

    // Reverse a linked list
    ListNode* reverse(ListNode* head) {

        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr != nullptr) {

            ListNode* next = curr->next;
            curr->next = prev;

            prev = curr;
            curr = next;
        }

        return prev;
    }

    // Returns the kth node from temp
    ListNode* getKthNode(ListNode* temp, int k) {

        k--;

        while (temp != nullptr && k > 0) {
            temp = temp->next;
            k--;
        }

        return temp;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* temp = head;
        ListNode* prevLast = nullptr;

        while (temp != nullptr) {

            ListNode* kthNode = getKthNode(temp, k);

            // Less than k nodes remaining
            if (kthNode == nullptr) {

                if (prevLast)
                    prevLast->next = temp;

                break;
            }

            // Store next group's head
            ListNode* nextNode = kthNode->next;

            // Disconnect current group
            kthNode->next = nullptr;

            // Reverse current group
            ListNode* newHead = reverse(temp);

            // Connect previous group
            if (temp == head)
                head = newHead;
            else
                prevLast->next = newHead;

            // temp becomes the last node after reversal
            prevLast = temp;

            // Move to next group
            temp = nextNode;
        }

        return head;
    }
};

// Function to create linked list
ListNode* createList(int n) {

    if (n == 0)
        return nullptr;

    int x;
    cin >> x;

    ListNode* head = new ListNode(x);
    ListNode* temp = head;

    for (int i = 1; i < n; i++) {
        cin >> x;
        temp->next = new ListNode(x);
        temp = temp->next;
    }

    return head;
}

// Function to print linked list
void printList(ListNode* head) {

    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }

    cout << endl;
}

int main() {

    int n;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter linked list elements: ";
    ListNode* head = createList(n);

    int k;

    cout << "Enter value of k: ";
    cin >> k;

    Solution obj;

    head = obj.reverseKGroup(head, k);

    cout << "Linked List after reversing every " << k << " nodes:\n";

    printList(head);

    return 0;
}