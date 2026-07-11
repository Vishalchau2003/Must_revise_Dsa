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
    Node *reverse(Node *head)
    {
        Node *nexter = nullptr;
        Node *prever = nullptr;
        Node *curr = head;

        while (curr)
        {
            prever = curr->next;

            curr->next = nexter;
            curr->prev = prever;

            nexter = curr;
            curr = prever;
        }

        return nexter;
    }
};

void printList(Node *head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    // Creating the doubly linked list: 1 <-> 2 <-> 3 <-> 4
    Node *head = new Node(1);
    Node *second = new Node(2);
    Node *third = new Node(3);
    Node *fourth = new Node(4);

    head->next = second;
    second->prev = head;

    second->next = third;
    third->prev = second;

    third->next = fourth;
    fourth->prev = third;

    cout << "Original List: ";
    printList(head);

    Solution obj;
    head = obj.reverse(head);

    cout << "Reversed List: ";
    printList(head);

    return 0;
}