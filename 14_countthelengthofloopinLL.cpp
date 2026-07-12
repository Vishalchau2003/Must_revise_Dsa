#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

int lengthOfLoop(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {

        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {

            int len = 1;
            slow = slow->next;

            while (slow != fast) {
                slow = slow->next;
                len++;
            }

            return len;
        }
    }

    return 0;
}

int main() {
    int n;

    cout << "Enter number of nodes: ";
    cin >> n;

    if (n == 0) {
        cout << "Length of loop = 0";
        return 0;
    }

    Node* head = nullptr;
    Node* tail = nullptr;

    cout << "Enter node values: ";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        Node* newNode = new Node(x);

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Create a loop
    int pos;
    cout << "Enter loop position (0 for no loop, 1-based index otherwise): ";
    cin >> pos;

    if (pos != 0) {
        Node* temp = head;
        for (int i = 1; i < pos; i++) {
            temp = temp->next;
        }
        tail->next = temp;
    }

    int ans = lengthOfLoop(head);

    cout << "Length of loop = " << ans << endl;

    return 0;
}