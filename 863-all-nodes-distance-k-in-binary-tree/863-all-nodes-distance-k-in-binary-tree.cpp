/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    void findPar(TreeNode *root, unordered_map<int,TreeNode*>&m){
         queue<TreeNode*>q;
         q.push(root);
         while(!q.empty()){
             TreeNode *node = q.front();
             q.pop();
            if(node->left){
                q.push(node->left);
                m[node->left->val] = node;
            }
            if(node->right){
                q.push(node->right);
                m[node->right->val] = node;
            }
         }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int>res;        
        TreeNode* tarNode = target;
        unordered_map<int,TreeNode*>parents;
        unordered_set<int>vis;
        findPar(root,parents);
        queue<TreeNode*>q;
        q.push(tarNode);
        vis.insert(tarNode->val);
        int curDist = 0;
        while(!q.empty() && curDist<k){
            int size = q.size();
            for(int i=0;i<size;i++){
                TreeNode *node = q.front();
                q.pop();
                if(node->left && !vis.count(node->left->val)){
                    q.push(node->left);
                    vis.insert(node->left->val);
                }
                if(node->right && !vis.count(node->right->val)){
                    q.push(node->right);
                    vis.insert(node->right->val);
                }
                if(parents.find(node->val)!=parents.end() && !vis.count(parents[node->val]->val)){
                    q.push(parents[node->val]);
                    vis.insert(parents[node->val]->val);
                }
            }
            curDist++;
        }
        while(!q.empty()){
            res.push_back(q.front()->val);
            q.pop();
        }
        return res;
    }
};