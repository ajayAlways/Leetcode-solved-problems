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
    ListNode* partition(ListNode* head, int x) {
        ListNode *dummy1 = new ListNode(),*dummy2 = new ListNode(),*head1 = dummy1, *head2 = dummy2;
        while(head){
            if(head->val < x){
                head1->next = head;
                head1 = head1->next;
            }
            else{
                head2->next = head;
                head2 = head2->next;
            }
            head = head->next;
        }
        head1->next = dummy2->next;
        head2->next = NULL;
        head = dummy1->next;
        delete(dummy1);
        delete(dummy2);
        return head;
    }
};