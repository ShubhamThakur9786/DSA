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
    ListNode* getMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next;
            if(fast->next) {
                fast = fast->next;
            }
        }
        return slow;
    }
    ListNode* deleteMiddle(ListNode* head) {
        
        if(head->next == NULL) {
            return NULL;
        }
        ListNode* middleNode = getMiddle(head);
        
        ListNode* curr = head;
        ListNode* prev = NULL;
        while(curr != middleNode) {
            ListNode* forw = curr->next;
            prev = curr;
            curr = forw;
        }

        prev->next = curr->next;
        curr->next = NULL;
        return head;
    }
};