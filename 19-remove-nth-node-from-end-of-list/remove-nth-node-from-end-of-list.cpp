/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = 0;

        ListNode* temp = head;
        while(temp) {
            size++;
            temp = temp->next;
        }

        int pos = size - n;

        if(pos == 0) {
            ListNode* del = head;
            head = head->next;
            delete del;
            return head;
        }
        int i=0;
        ListNode* curr = head;
        ListNode* prev = NULL;
        while(i<pos) {
            prev = curr;
            curr = curr->next;
            i++;
        }

        prev->next = curr->next;
        curr->next = NULL;
        return head;
    }
};