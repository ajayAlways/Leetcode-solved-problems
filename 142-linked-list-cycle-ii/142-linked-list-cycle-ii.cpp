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
        // With extra space         
        // ListNode *temp = head;
        // unordered_set<ListNode*>s;
        // while(temp!=NULL){
        //     if(s.find(temp)!=s.end()) return temp;
        //     else s.insert(temp);
        //     temp = temp -> next;
        // }
        ListNode *fast = head,*slow=head;
        while(true){
            if(fast==NULL || fast->next==NULL || fast->next->next==NULL) return NULL;
            slow=slow->next;
            fast=fast->next->next;
            if(fast==slow) break;
        }
        slow=head;
        while(slow!=fast){
            slow=slow->next;
            fast=fast->next;
        }
        return slow;
    }
};