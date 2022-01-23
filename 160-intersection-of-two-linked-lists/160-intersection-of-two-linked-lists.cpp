/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *h1=headA,*h2=headB,*h;
        while(h1->next!=NULL) h1 = h1->next;
        h1->next = h2;
        h=h1;
        h1 = headA;
        h2 = headA;
        while(true){
            if(h1==NULL || h1->next==NULL || h1->next->next==NULL){
                h->next = NULL;
                return NULL;
            }   
            h1=h1->next->next;
            h2=h2->next;
            if(h1==h2) break;
        }
        h1=headA;
        while(h1!=h2){
            h1=h1->next;
            h2=h2->next;
        }
        h->next = NULL;
        return h2;
    }
};