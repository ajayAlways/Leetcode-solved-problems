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
    
    void solve(TreeNode* root, int idx, int level, vector<vector<pair<int,int>>>&res){
        if(root==NULL) return;
        
        res[idx].push_back({level,root->val});
        solve(root->left,idx-1,level+1,res);
        solve(root->right,idx+1,level+1,res);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<pair<int,int>>>temp(2005);
        vector<vector<int>>res;
        solve(root,1000,0,temp);
        
        for(auto& i:temp){
            if(!i.empty()){
                sort(i.begin(),i.end());
                res.push_back({});
                for(auto& j:i) res.back().push_back(j.second);
            }
        }
        
        return res;
    }
};