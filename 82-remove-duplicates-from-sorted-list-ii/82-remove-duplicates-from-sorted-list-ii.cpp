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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode *cur=head,*prev=dummy;
        
        while(cur!=NULL && cur->next!=NULL){
            if(cur->val == cur->next->val){
                int dupl = cur->val;
                while(cur!=NULL && cur->val==dupl) cur=cur->next;
                prev->next = cur;
            }
            else{
                cur = cur->next;
                prev = prev->next;
            }
        }
        return dummy->next;
    }
};