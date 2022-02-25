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
class FindElements {
private:
    vector<int> check = vector<int>(10000000,0);
public:
    void build(TreeNode* child,TreeNode* parent){
        if(!child) return;
        if(parent){
            if(parent->left==child) child->val = 2*parent->val + 1;
            else child->val = 2*parent->val + 2;
        }
        else child->val = 0;
        check[child->val] = 1;
        build(child->left,child);
        build(child->right,child);
    }
    FindElements(TreeNode* root) {
        build(root,NULL);
    }
    
    bool find(int target) {
        return check[target];
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */