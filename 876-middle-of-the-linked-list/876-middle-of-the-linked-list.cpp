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
    ListNode* middleNode(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        int size=0,count=0;
        ListNode* temp = head;
        while(temp!=NULL){
            size++;
            temp=temp->next;
        }
        while(true){
            count++;
            head=head->next;
            if(count==(size/2)) return head;
        }
        return head;
    }
};