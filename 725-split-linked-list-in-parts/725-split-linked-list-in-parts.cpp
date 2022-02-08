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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int len=0,parts=k;
        ListNode* temp = head;
        ListNode* prev=NULL;
        vector<int>split;
        vector<ListNode*>res;
        while(temp!=NULL){
            temp = temp->next;
            len++;
        }
       
        while(k){
            int i=ceil(float(len)/k);
            split.push_back(i);
            len = (len-i)>0 ? len-=i:0;
            k--;
        }
        temp = head;
        for(int i=0;i<parts;i++){
            res.push_back(temp);
            for(int p=0;p<split[i]-1;p++){
                if(temp) temp=temp->next;  
            }
            ListNode* next = NULL;
            if(temp){
                next = temp->next;
                temp->next=NULL;
            }
            temp = next;
        }
        return res;
    }
};