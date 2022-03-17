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
    ListNode* merge(ListNode* head1, ListNode* head2){
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;
        while(head1 && head2){
            if(head1->val < head2->val){
                cur->next = head1;
                head1 = head1->next;
            }
            else{
                cur->next = head2;
                head2 = head2->next;
            }
            cur = cur->next; 
        }
        if(head1) cur->next = head1;
        if(head2) cur->next = head2;
        
        return dummy->next;
    }
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* slow = dummy;
        ListNode* fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* listTwo = slow->next;
        slow->next = NULL;
        return merge(sortList(head),sortList(listTwo));
    }
};