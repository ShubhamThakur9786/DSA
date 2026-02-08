#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

// Insert at head
void insertAtHead(Node *&head, int val)
{
    Node *newNode = new Node(val);
    if (head == nullptr)
    {
        newNode->next = newNode; // circular link
        head = newNode;
        return;
    }

    // Find last node to update its next
    Node *temp = head;
    while (temp->next != head)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = head;
    head = newNode; // update head
}

// Insert at tail
void insertAtTail(Node *&head, int val)
{
    Node *newNode = new Node(val);
    if (head == nullptr)
    {
        newNode->next = newNode;
        head = newNode;
        return;
    }

    Node *temp = head;
    while (temp->next != head)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = head;
}

// Delete node by position (1-based index)
void deleteNode(Node *&head, int pos)
{
    if (head == nullptr)
        return;

    // Single node
    if (head->next == head && pos == 1)
    {
        delete head;
        head = nullptr;
        return;
    }

    Node *curr = head;
    Node *prev = nullptr;

    // Deleting head
    if (pos == 1)
    {
        // Find last node to update its next
        while (curr->next != head)
            curr = curr->next;
        Node *temp = head;
        curr->next = head->next;
        head = head->next;
        delete temp;
        return;
    }

    // Deleting other positions
    int count = 1;
    curr = head;
    while (count < pos)
    {
        prev = curr;
        curr = curr->next;
        count++;
        if (curr == head)
        { // position out of bounds
            cout << "Position out of bounds\n";
            return;
        }
    }

    prev->next = curr->next;
    delete curr;
}

// Print circular linked list
void printList(Node *head)
{
    if (head == nullptr)
    {
        cout << "List is empty\n";
        return;
    }

    Node *temp = head;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

int main()
{
    Node *head = nullptr;

    insertAtHead(head, 10);
    insertAtHead(head, 20);
    insertAtTail(head, 5);
    insertAtTail(head, 1);

    cout << "Circular Linked List: ";
    printList(head);

    deleteNode(head, 1); // delete head
    cout << "After deleting position 1: ";
    printList(head);

    deleteNode(head, 3); // delete last node
    cout << "After deleting position 3: ";
    printList(head);

    deleteNode(head, 10); // out of bounds
    return 0;
}
