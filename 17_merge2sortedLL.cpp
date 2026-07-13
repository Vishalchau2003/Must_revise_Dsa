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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        ListNode* t1 = list1;
        ListNode* t2 = list2;

        ListNode* dummynode = new ListNode(-1);
        ListNode* temp = dummynode;

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

        if (t1 != nullptr) {
            temp->next = t1;
        }
        else {
            temp->next = t2;
        }

        return dummynode->next;
    }
};

// Function to print linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {

    // First Linked List: 1 -> 2 -> 4
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(4);

    // Second Linked List: 1 -> 3 -> 4
    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);

    Solution obj;

    ListNode* mergedHead = obj.mergeTwoLists(list1, list2);

    cout << "Merged Linked List: ";
    printList(mergedHead);

    return 0;
}