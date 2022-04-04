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
    ListNode* swapNodes(ListNode* head, int k) {
        if(head==NULL || head->next==NULL) return head;
        int size=0,num,l=0;
        ListNode* temp = head;
        while(temp!=NULL){
            size++;
            if(size==k) num = temp->val;
            temp = temp->next;
        }
        temp=head;
        while(temp!=NULL){
            l++;
            if(l==size-k+1){
                int t = temp->val;
                temp->val = num;
                num=t;
                break;
            }
            temp=temp->next;
        }
        l=0;
        temp = head;
        while(temp!=NULL){
            l++;
            if(l==k){
                temp->val = num;
                break;
            }
            temp = temp->next;
        }
        return head;
    }
};