// Reverse a linked list
// Difficulty: Easy
// You are given the head of a singly linked list. You have to reverse the linked list and return the head of the reversed list.

// Examples:

// Input:

// Output: 4 -> 3 -> 2 -> 1
// Explanation: After reversing the linkedList

class Solution
{
public:
    Node *reverseList(Node *head)
    {
        // code here
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        Node *curr = head;
        Node *prev = NULL;

        while (curr != NULL)
        {
            Node *forw = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forw;
        }

        return prev;
    }
};

// Reverse a Doubly Linked List
// Difficulty: Easy
// You are given the head of a doubly linked list. You have to reverse the doubly linked list and return its head.

// Examples:

// Input:

// Output: 5 <-> 4 <-> 3
// Explanation: After reversing the given doubly linked list the new list will be 5 <-> 4 <-> 3.

class Solution
{
public:
    Node *reverse(Node *head)
    {
        // code here
        Node *curr = head;
        Node *prev = NULL;

        while (curr != NULL)
        {
            Node *forw = curr->next;
            curr->next = prev;
            curr->prev = forw;
            prev = curr;
            curr = forw;
        }

        return prev;
    }
};
