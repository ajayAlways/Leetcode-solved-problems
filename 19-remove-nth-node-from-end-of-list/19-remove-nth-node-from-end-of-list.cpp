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
        if(head->next==NULL && n>0) return NULL;
        int size=0;
        ListNode *temp = head,*temp2=head;
        while(temp!=NULL){
            size++;
            temp=temp->next;
        }
        if(size==n) return head->next;
        for(int i=1;i<(size-n);i++){
            temp2=temp2->next;
        }
        ListNode* node = temp2->next;
        temp2->next = node->next;
        delete(node);
        return head;
    }
};