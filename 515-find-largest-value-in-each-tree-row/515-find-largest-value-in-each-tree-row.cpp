/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int maxLevel=1;
public:
    void dfs(TreeNode* root,int l,vector<int> &level){
        if(!root) return;
        level[l-1] = max(level[l-1],root->val);
        maxLevel = max(maxLevel,l);
        dfs(root->left,l+1,level);        
        dfs(root->right,l+1,level);
    }
    vector<int> largestValues(TreeNode* root) {
        if(!root) return {};
        vector<int>level(10000,INT_MIN),res;
        // queue<TreeNode*>q;
        // vector<int>res;
        // q.push(root);
        // while(!q.empty()){
        //     int size = q.size(),maxVal=INT_MIN;
        //     while(size--){
        //         TreeNode* node = q.front();
        //         q.pop();
        //         maxVal = max(maxVal, node->val);
        //         if(node->left) q.push(node->left);
        //         if(node->right) q.push(node->right);
        //     }
        //     res.push_back(maxVal);
        // }
        dfs(root,1,level);
        for(int i=0;i<maxLevel;i++){
            res.push_back(level[i]);
        }
        return res;
    }
};