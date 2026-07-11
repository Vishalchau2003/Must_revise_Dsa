// -- Given the head of a doubly-linked list, a position p, and an integer x.
// Add a new node with value x at the position just after pth node in the doubly linked list and return the head of the updated list.--

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int x)
    {
        data = x;
        next = nullptr;
        prev = nullptr;
    }
};

class Solution
{
public:
    Node *insertAtPos(Node *head, int p, int x)
    {
        Node *mover = head;

        for (int i = 0; i < p; i++)
        {
            mover = mover->next;
        }

        Node *node = new Node(x);

        node->next = mover->next;
        node->prev = mover;

        if (mover->next != nullptr)
        {
            mover->next->prev = node;
        }

        mover->next = node;

        return head;
    }
};

void printList(Node *head)
{
    Node *temp = head;

    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main()
{
    // Creating: 1 <-> 2 <-> 3
    Node *head = new Node(1);
    Node *second = new Node(2);
    Node *third = new Node(3);

    head->next = second;
    second->prev = head;

    second->next = third;
    third->prev = second;

    Solution obj;

    // Insert 10 after position 1 (0-based indexing)
    head = obj.insertAtPos(head, 1, 10);

    printList(head);

    return 0;
}