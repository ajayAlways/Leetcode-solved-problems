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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *head = list1, *start,*end;
        int i=0;
        while(head!=NULL){
            if(i+1==a) start = head;
            else if(i==b){
                end = head;
                break;
            }
            i++;
            head = head->next;
        }
        start->next = list2;
        while(list2->next!=NULL) list2=list2->next;
        list2->next = end->next;
        
        return list1;
    }
};