#include <iostream>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};

bool isPalindrome(ListNode* head) {

    if (head == nullptr || head->next == nullptr)
        return true;

    // Find middle
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Skip middle node if odd length
    if (fast != nullptr)
        slow = slow->next;

    // Reverse second half
    ListNode* prev = nullptr;
    ListNode* curr = slow;

    while (curr) {
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    // Compare both halves
    ListNode* left = head;
    ListNode* right = prev;

    while (right) {
        if (left->val != right->val)
            return false;

        left = left->next;
        right = right->next;
    }

    return true;
}

int main() {

    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    if (n == 0) {
        cout << "Empty list is a palindrome.";
        return 0;
    }

    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    cout << "Enter node values: ";

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        ListNode* newNode = new ListNode(x);

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    if (isPalindrome(head))
        cout << "Palindrome Linked List" << endl;
    else
        cout << "Not a Palindrome Linked List" << endl;

    return 0;
}