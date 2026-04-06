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
    ListNode* removeZeroSumSublists(ListNode* head) {
        unordered_map<int, ListNode*> mp;
        ListNode* dummyNode = new ListNode(0);
        dummyNode->next = head;
        ListNode* curr = dummyNode;
        int prefixSum = 0;
        while(curr) {
            prefixSum += curr->val;
            if(mp.find(prefixSum) != mp.end()) {
                ListNode* prev = mp[prefixSum];
                ListNode* temp = prev->next;
                int sum = prefixSum;
                while(temp != curr) {
                    sum += temp->val;
                    mp.erase(sum);
                    temp = temp->next;
                }
                prev->next = curr->next;
            }
            else {
                mp[prefixSum] = curr;
            }
            curr = curr->next;
        }

        return dummyNode->next;
    }
};