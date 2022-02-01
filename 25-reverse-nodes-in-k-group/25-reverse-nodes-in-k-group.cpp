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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL) return head;
        ListNode *prev=NULL,*cur=head,*next=NULL;
        int count=0;
        while(cur!=NULL){
            count++;
            cur=cur->next;
        }
        if(count<k) return head;
        cur=head;
        count=0;
        while(cur!=NULL && count<k){
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur=next;
            count++;
        }
        if(cur!=NULL) head->next = reverseKGroup(cur,k);
        return prev;
    }
};