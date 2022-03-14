/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL) return head;
        unordered_map<Node*,int>m1;
        unordered_map<int,Node*>m2;
        Node* temp = head;
        int i=0;
        while(temp!=NULL){
            m1[temp]=i;
            i++;
            temp = temp->next;
        }
        temp = head;
        i=0;
        Node* dummy = new Node(0);
        Node* prev = dummy;
        while(temp!=NULL){
            Node* node = new Node(temp->val);
            m2[i++]=node;
            prev->next = node;
            prev = node;
            temp=temp->next;
        }
        Node* temp1 = head;
        Node* temp2 = dummy->next;
        while(temp1 && temp2){
            if(temp1->random==NULL) temp2->random=NULL;
            else temp2->random = m2[m1[temp1->random]];
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return dummy->next;
    }
};