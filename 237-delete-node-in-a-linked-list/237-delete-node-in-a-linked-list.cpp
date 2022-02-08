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
    void deleteNode(ListNode* node) {
        ListNode *ptr = node;
        ListNode* prev=NULL;
        while(ptr->next!=NULL){
            prev = ptr==node ? node:ptr;
            ptr->val = ptr->next->val;
            ptr = ptr->next;
        }
        prev->next = NULL;
        delete(ptr);
    }
};