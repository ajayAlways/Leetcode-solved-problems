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
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next==NULL) return NULL;
        int count=0;
        // ListNode *head1 = head;
        ListNode *fast = head,*slow=head,*dummy = new ListNode(0);
        dummy->next = head;
        slow=dummy;
        while(fast!=NULL &&  fast->next!=NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        // head1 = head;
        // for(int i=0;i<count/2 -1;i++){
        //     head1=head1->next;
        // }
        ListNode *temp = slow->next;
        slow->next = temp->next;
        delete(temp);
        return head;
    }
};