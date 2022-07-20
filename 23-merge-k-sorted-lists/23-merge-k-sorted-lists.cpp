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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // TC - O(n^2);
        // int n = lists.size();
        // if(n==0) return NULL;
        // if(n==1 && !lists[0]) return NULL;
        // while(lists.size()>1){
        //     ListNode *dummy = new ListNode(),*root=dummy,*l1=lists[lists.size()-1],*l2=lists[lists.size()-2];
        //     while(l1 && l2){
        //         if(l1->val < l2->val){
        //             root->next = l1;
        //             l1 = l1->next;
        //         }
        //         else{
        //             root->next = l2;
        //             l2 = l2->next;
        //         }
        //         root = root->next;
        //     }
        //     if(l1) root->next = l1;
        //     if(l2) root->next = l2;
        //     lists.pop_back();
        //     lists.pop_back();
        //     lists.push_back(dummy->next);
        // }
        // return lists[0];
        
            priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>>minHeap;
        ListNode *dummy = new ListNode(), *head = dummy;
        for(auto& i:lists){
            if(i!=NULL) minHeap.push({i->val,i});
        }
        while(!minHeap.empty()){
            ListNode* node = minHeap.top().second;
            minHeap.pop();
            head->next = node;
            head = head->next;
            if(node->next) minHeap.push({node->next->val,node->next});
        }
        head = dummy->next;
        delete(dummy);
        return head;
    }
};