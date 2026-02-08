#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// 1. create a single node in linkedlist with data and pointer => class of Node create karo and instance create karke data and next address print karo
// class Node
// {
// public:
//     int data;
//     Node *next;

//     Node(int data)
//     {
//         this->data = data;
//         this->next = NULL;
//     }
// };

// int main()
// {
//     Node *node1 = new Node(10);
//     cout << node1->data << endl;
//     cout << node1->next << endl;
// }

// 2. InsertAtHead in linkedList, traverse a linkedList, insertAtTail in linkedlist, insertAtMiddle in linkedlist and delete any node in linkedlist
class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    ~Node()
    {
        int val = this->data;
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }

        cout << "Memory Free for value " << val << endl;
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

void InsertAtHead(Node *&head, int d)
{
    // create node first
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node *&tail, int d)
{
    // create node first
    Node *temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

void insertAtMiddle(Node *&tail, Node *&head, int pos, int d)
{
    if (pos == 1)
    {
        InsertAtHead(head, d);
        return;
    }

    // insert at middle
    Node *temp = head;
    int cnt = 1;
    while (cnt < pos - 1)
    {
        temp = temp->next;
        cnt++;
    }

    if (temp->next == NULL)
    {
        insertAtTail(tail, d);
        return;
    }

    Node *newNode = new Node(d);
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteNode(Node *&head, int pos)
{
    if (pos == 1)
    {
        Node *temp = head;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        int cnt = 1;
        Node *curr = head;
        Node *prev = NULL;
        while (cnt < pos)
        {
            cnt++;
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

int main()
{
    Node *node1 = new Node(10);
    cout << node1->data << endl;
    cout << node1->next << endl;
    Node *tail = node1;
    Node *head = node1;

    insertAtTail(tail, 20);
    print(head);
    insertAtTail(tail, 30);
    print(head);
    insertAtMiddle(tail, head, 3, 25);
    print(head);
    insertAtMiddle(tail, head, 5, 40);
    print(head);

    deleteNode(head, 3);
    print(head);
}
