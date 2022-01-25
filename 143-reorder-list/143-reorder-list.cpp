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
    void reorderList(ListNode* head) {
        if(head!=NULL && head->next!=NULL && head->next->next!=NULL){
            stack<ListNode*>st;
            ListNode *head1 = head;
            int count=0;
            while(head1!=NULL){
                st.push(head1);
                count++;
                head1 = head1->next;
            }
            head1 = head;
            for(int i=0;i<count/2;i++){
                ListNode *node = st.top(),*temp=head1->next;
                st.pop();
                head1->next = node;
                node->next = temp;
                head1=temp;
            }
            head1->next = NULL;
        }
        
    }
};