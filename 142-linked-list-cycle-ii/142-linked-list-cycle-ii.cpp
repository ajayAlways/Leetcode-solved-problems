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
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL|| head->next==NULL) return NULL;
        ListNode *temp = head;
        unordered_set<ListNode*>s;
        while(temp!=NULL){
            if(s.find(temp)!=s.end()) return temp;
            else s.insert(temp);
            temp = temp -> next;
        }
        return NULL;
    }
};