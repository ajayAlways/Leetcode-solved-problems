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
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL) return {};
        queue<TreeNode*>q;
        vector<vector<int>>ans;
        q.push(root);
        int i=1;
        while(!q.empty()){
            int size = q.size();
            ans.push_back(vector<int>(size,0));
            for(int j=0;j<size;j++){
                TreeNode* node = q.front();
                q.pop();
                if(i%2!=0){
                    ans.back()[j]=node->val;
                }
                else{
                    ans.back()[size-j-1] = node->val;
                }
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            i++;
        }
        return ans;
    }
};