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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(INT_MIN),*prev,*cur,*next,*lef,*righ;
        dummy->next = head;
        head = dummy;
        int count = left - 1;
        while(count){
            head = head->next;
            count--;
        }
        count = right - left+1;
        lef = head;
        righ = head->next;
        prev = NULL;
        cur = head->next;
        while(cur && count){
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
            count--;
        }
        lef->next = prev;
        righ->next = cur;
        
        head = dummy->next;
        delete(dummy);
        
        return head;
    }
};