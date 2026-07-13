
#include <iostream>
using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode* next;

    ListNode() {
        val = 0;
        next = nullptr;
    }

    ListNode(int x) {
        val = x;
        next = nullptr;
    }

    ListNode(int x, ListNode* next) {
        val = x;
        this->next = next;
    }
};

class Solution {
public:

    // Merge two sorted linked lists
    ListNode* merge(ListNode* list1, ListNode* list2) {

        ListNode* t1 = list1;
        ListNode* t2 = list2;

        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;

        while (t1 != nullptr && t2 != nullptr) {

            if (t1->val < t2->val) {
                temp->next = t1;
                temp = t1;
                t1 = t1->next;
            }
            else {
                temp->next = t2;
                temp = t2;
                t2 = t2->next;
            }
        }

        if (t1 != nullptr)
            temp->next = t1;
        else
            temp->next = t2;

        return dummyNode->next;
    }

    // Find middle node
    ListNode* find_mid(ListNode* head) {

        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    // Merge Sort
    ListNode* sortList(ListNode* head) {

        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode* middle = find_mid(head);

        ListNode* left = head;
        ListNode* right = middle->next;

        middle->next = nullptr;

        left = sortList(left);
        right = sortList(right);

        return merge(left, right);
    }
};

// Print Linked List
void printList(ListNode* head) {

    while (head != nullptr) {
        cout << head->val << " -> ";
        head = head->next;
    }

    cout << "NULL" << endl;
}

int main() {

    // Create Linked List: 4 -> 2 -> 1 -> 3 -> 5
    ListNode* head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(5);

    cout << "Original List:\n";
    printList(head);

    Solution obj;

    head = obj.sortList(head);

    cout << "\nSorted List:\n";
    printList(head);

    return 0;
}