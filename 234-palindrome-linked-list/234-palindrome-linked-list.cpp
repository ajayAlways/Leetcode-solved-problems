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
    
    ListNode* reverseLL(ListNode* head){
        ListNode *prev = NULL, *cur = head, *next;
        while(cur){
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur  = next;
        }
        return prev;
    }
    
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;
        ListNode *slow = head, *fast = head->next,*tail;
        
        while(slow && fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* temp = slow->next;
        slow->next = NULL;
        tail = reverseLL(temp);
        
        while(head && tail){
            if(head->val != tail->val) return false;
            head = head->next;
            tail = tail->next;
        }
        return true;
    }
};