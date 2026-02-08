#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

// Starting with doubliy linkedlist
// class Node
// {
// public:
//     int data;
//     Node *next;
//     Node *prev;

//     Node(int data)
//     {
//         this->data = data;
//         this->next = NULL;
//         this->prev = NULL;
//     }
// };

// int main()
// {
//     Node *node1 = new Node(10);
//     cout << node1->data << endl;
//     cout << node1->next << endl;
//     cout << node1->prev << endl;
// }

// insert, delete, traverse a doubly linkedlists
class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
    ~Node()
    {
        cout << "Memory Free for node with data: " << data << endl;
    }
};

void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int getLen(Node *&head)
{
    if (head->next == NULL)
    {
        return 1;
    }
    Node *temp = head;
    int cnt = 0;
    while (temp != NULL)
    {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}
void insertAtHead(Node *&head, Node *&tail, int d)
{
    // create node
    if (head == NULL)
    {
        head = new Node(d);
        tail = head;
        return;
    }
    Node *temp = new Node(d);
    temp->next = head;
    head->prev = temp;
    head = temp;
}

void insertAtTail(Node *&tail, Node *&head, int d)
{
    // check if head is null or not if head is null then create head and return
    if (head == NULL)
    {
        Node *head = new Node(d);
        tail = head;
        return;
    }
    // create a node
    Node *temp = new Node(d);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}

void insertAtMiddle(Node *&head, Node *&tail, int pos, int d)
{
    if (pos == 1)
    {
        insertAtHead(head, tail, d);
        return;
    }

    Node *temp = head;
    int cnt = 1;
    while (cnt < pos - 1)
    {
        temp = temp->next;
        cnt++;
    }
    if (temp->next == NULL)
    {
        insertAtTail(tail, head, d);
        return;
    }

    // create a node
    Node *nodetoinsert = new Node(d);
    nodetoinsert->next = temp->next;
    temp->next->prev = nodetoinsert;
    nodetoinsert->prev = temp;
    temp->next = nodetoinsert;
}

void deleteNode(Node *&head, int pos)
{
    if (head == NULL || pos <= 0)
        return;

    Node *curr = head;

    // delete first node
    if (pos == 1)
    {
        head = curr->next;
        if (head != NULL)
            head->prev = NULL;
        delete curr;
        return;
    }

    int cnt = 1;
    while (cnt < pos && curr != NULL)
    {
        curr = curr->next;
        cnt++;
    }

    if (curr == NULL)
        return;

    if (curr->prev != NULL)
        curr->prev->next = curr->next;

    if (curr->next != NULL)
        curr->next->prev = curr->prev;

    delete curr;
}

int main()
{
    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = head;

    print(head);
    insertAtHead(head, tail, 9);
    print(head);
    insertAtHead(head, tail, 8);
    print(head);
    insertAtHead(head, tail, 7);
    print(head);
    insertAtHead(head, tail, 6);
    print(head);
    insertAtHead(head, tail, 5);
    print(head);

    insertAtTail(tail, head, 20);
    print(head);
    insertAtTail(tail, head, 30);
    print(head);

    insertAtMiddle(head, tail, 7, 15);
    print(head);

    deleteNode(head, 1);
    print(head);
    // cout << getLen(head);
}
