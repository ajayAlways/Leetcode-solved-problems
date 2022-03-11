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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL) return head;
        int size = 0;
        ListNode* temp = head;
        while(temp!=NULL){
            temp = temp->next;
            size++;
        }
        k%=size;
        if(k==size || k==0) return head;
        
        temp = head;
        for(int i=0;i<size-k-1;i++){
            temp = temp->next;
        }
        ListNode* newHead = temp->next;
        temp->next = NULL;
        temp = newHead;
        while(temp->next!=NULL) temp = temp->next;
        temp->next = head;
        
        return newHead;
    }
};