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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) {
		return root;
	}
	else if(key<root->val){ 
		root->left = deleteNode(root->left,key);
	}
	else if(key>root->val) {
		root->right = deleteNode(root->right,key);
	}
	else{
		//case 1 (if it is a leaf node)
		if(root->left==NULL && root->right==NULL){
			delete(root);
			root=NULL;
		}
		//case 2 (if node has only one subtree)
		else if(root->left==NULL){
			TreeNode* temp=root;
			root=root->right;
			delete(temp);
		}
		else if(root->right==NULL){
			TreeNode* temp = root;
			root=root->left;
			delete(temp);
		}

		//case 3 if node has two subtrees
		else{
            TreeNode* temp = root->right;
			while(temp!=NULL && temp->left!=NULL) temp=temp->left;
			root->val = temp->val;
			root->right = deleteNode(root->right,temp->val);
		}
	}
	return root;
    }
};