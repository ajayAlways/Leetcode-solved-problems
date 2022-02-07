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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==NULL || head->next==NULL) return head;
        ListNode *dummy = new ListNode(-1);
        ListNode *prev=NULL,*cur=dummy,*next,*temp1,*temp2;
        dummy->next = head;
        
        for(int i=1;i<left;i++) cur = cur->next;
        temp1 = cur;
        temp2 = cur->next;
        cur = cur->next;
        for(int i=0;i<=right-left;i++){
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        temp1->next = prev;
        temp2->next = cur;
        
        return dummy->next;
    }
};