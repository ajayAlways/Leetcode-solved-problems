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

ListNode* reverseLL(ListNode* head){
    ListNode *prev=NULL,*cur=head,*next;
    while(cur!=NULL){
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head1 = reverseLL(l1),*head2 = reverseLL(l2),*newhead=new ListNode(),*prev=newhead;
        int carry=0;
        while(head1 || head2 || carry){
            int sum=0;
            if(head1){
                sum+=head1->val;
                head1=head1->next;
            }
            if(head2){
                sum+=head2->val;
                head2=head2->next;
            }
            sum+=carry;
            carry=sum/10;
            sum%=10;
            ListNode *temp = new ListNode(sum);
            prev->next = temp;
            prev=temp;
        }
        return reverseLL(newhead->next);
    }
};