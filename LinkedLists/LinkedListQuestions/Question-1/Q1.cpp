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