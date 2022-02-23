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
    int max(vector<int>nums, int l, int r){
        int maxi = nums[l],maxPos=l;
        for(int i=l;i<r;i++){
            if(nums[i]>maxi){
                maxi = nums[i];
                maxPos = i;
            }
        }
        return maxPos;
    }
    TreeNode* helper(TreeNode* root, vector<int>nums, int l, int r){
        if(l==r) return NULL;
        int maxPos = max(nums, l, r);
        root = new TreeNode(nums[maxPos]);
        root->left = helper(root->left, nums, l, maxPos);
        root->right = helper(root->right, nums, maxPos+1, r);
        
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        TreeNode* root = NULL;
        root = helper(root, nums, 0 ,nums.size());
        
        return root;
    }
};