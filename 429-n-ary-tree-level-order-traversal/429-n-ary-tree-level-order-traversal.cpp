/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(!root) return {};
        queue<Node*>q;
        q.push(root);
        vector<vector<int>>res;
        
        while(!q.empty()){
            int size = q.size();
            res.push_back({});
            for(int i=0;i<size;i++){
                Node* node = q.front();
                q.pop();
                res.back().push_back(node->val);
                for(int j=0;j<node->children.size();j++){
                    q.push(node->children[j]);
                }
            }
        }
        
        return res;
    }
};