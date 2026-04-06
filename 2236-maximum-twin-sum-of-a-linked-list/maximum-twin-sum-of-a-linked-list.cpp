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
    ListNode* revList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(curr) {
            ListNode* forw = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forw;
        }
        return prev;
    }
    int pairSum(ListNode* head) {
       ListNode* slow = head;
       ListNode* fast = head;

       while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
       }

       ListNode* second = revList(slow);
       ListNode* first = head;

       int maxi = 0;
       while(second) {
        int sum = first->val + second->val;
        maxi = max(maxi, sum);
        first = first->next;
        second = second->next;
       }
       return maxi;
    }
};