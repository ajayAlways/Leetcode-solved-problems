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
        if(head==NULL || head->next==NULL || head->next->next==NULL) return head;
        ListNode *odd=head,*even=head->next,*evenBegin=head->next;
        while((odd!=NULL && odd->next!=NULL) || (even!=NULL && even->next!=NULL)){
            if(odd->next) odd->next = odd->next->next;
            if(even->next) even->next = even->next->next;
            if(odd->next) odd=odd->next;
            even=even->next;
        }
        odd->next = evenBegin;
        return head;
    }
};