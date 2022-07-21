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
    
    ListNode* merge(ListNode* h1, ListNode* h2){
        ListNode *dummy = new ListNode(),*head = dummy;
        while(h1 && h2){
            if(h1->val < h2->val){
                head->next = h1;
                h1 = h1->next;
            }
            else{
                head->next = h2;
                h2 = h2->next;
            }
            head = head->next;
        }
        if(h1) head->next = h1;
        if(h2) head->next = h2;
        
        head = dummy->next;
        delete(dummy);
        
        return head;
    }
    
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *slow = head, *fast = head->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *head2 = slow->next,*mergedHead=NULL;
        slow->next = NULL;
        mergedHead = merge(sortList(head),sortList(head2));
        
        return mergedHead;
    }
};