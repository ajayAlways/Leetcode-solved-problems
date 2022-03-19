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
    int maxCount = 0;
    unordered_map<int,int>m;

    int subtreeSum(TreeNode* root){
        if(root==NULL) return 0;
        int sum = subtreeSum(root->left) + subtreeSum(root->right) + root->val;
        maxCount = max(maxCount, ++m[sum]);
        return sum;
    }
    
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int>res;
        subtreeSum(root);
        for(auto& i:m){
            if(i.second==maxCount) res.push_back(i.first);
        }
        
        return res;
    }
};