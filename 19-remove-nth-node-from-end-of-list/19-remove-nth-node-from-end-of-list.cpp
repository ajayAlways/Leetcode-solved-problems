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
        ListNode *temp = head,*cur;
        int i=0;
        for(;i<=n;i++){
            if(!temp) break;
            temp = temp->next;
        }
        if(!temp && i==n){
            ListNode* delHead = head;
            head = head->next;
            delete(delHead);
            return head;
        } 
        cur = head;
        while(temp){
            cur = cur->next;
            temp = temp->next;
        }
        temp = cur->next;
        if(cur->next) cur->next = cur->next->next;
        else cur->next = NULL;
        delete(temp);
        
        return head;
    }
};