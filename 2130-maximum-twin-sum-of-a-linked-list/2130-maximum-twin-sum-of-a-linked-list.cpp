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
    int pairSum(ListNode* head) {
        ListNode *slow=head,*fast=head,*prev=NULL,*next;
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            next = slow->next;
            slow->next = prev;
            prev=slow;
            slow=next;
        }
        int ans=0;
        while(slow!=NULL){
            int val = slow->val + prev->val;
            ans = max(ans,val);
            slow = slow->next;
            prev = prev->next;
        }
        return ans;
    }
};