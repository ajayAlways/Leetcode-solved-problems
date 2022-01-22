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

void reverse(ListNode* head, ListNode* &newHead){
    if(head->next==NULL){
        newHead = head;
        return;
    }
    ListNode* node = head;
    reverse(head->next,newHead);
    node->next->next = node;
    node->next = NULL;
}
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if( head==NULL || head->next==NULL) return head;
        ListNode* newHead;
        reverse(head,newHead);
        return newHead;
    }
};