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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next || !head->next->next) return head;
        ListNode *odd = head, *even = head->next, *temp=even->next,*temp2 = even;
        int count = 1;
        while(temp){
            if(count%2==0){
                even->next = temp;
                even = even->next;
            }
            else{
                odd->next = temp;
                odd = odd->next;
            }
            temp = temp->next;
            count++;
        }
        even->next = NULL;
        odd->next = temp2;
        
        return head;
    }
};