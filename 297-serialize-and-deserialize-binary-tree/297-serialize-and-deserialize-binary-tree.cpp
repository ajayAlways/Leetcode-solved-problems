/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res="";
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode *node = q.front();
            q.pop();
            if(node==NULL) res+='/';
            else{
                int val = node->val;
                if(val < 0){
                    res+='n';
                    val*=-1;
                }res+=to_string(val);
                res+='|';
                q.push(node->left);
                q.push(node->right);
            }
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data=="/") return NULL;
        vector<string>levelOrder;
        int j=0;
        for(int i=0;i<data.length();i++){
            if(data[i]=='/'){
                levelOrder.push_back("null");
                j++;
            }
            else{
                if(data[i]=='|'){
                    levelOrder.push_back(data.substr(j,i-j));
                    j=i+1;
                }
            }
        }
        queue<TreeNode*>q;
        int i=0;
        int num;
        string s = levelOrder[i++];
        if(s[0]=='n'){
            s.erase(s.begin()+0);
            num = -1*stoi(s);
        }
        else num = stoi(s);
        TreeNode *root = new TreeNode(num);
        q.push(root);
        while(!q.empty() && i<levelOrder.size()){
            int size = q.size();
            for(int j=0;j<size;j++){
                TreeNode *temp = q.front();
                q.pop();
                if(levelOrder[i]=="null"){
                    temp->left = NULL;
                    i++;
                }else{
                    int val=0;
                    string str = levelOrder[i];
                    if(str[0]=='n'){
                        str.erase(str.begin()+0);
                        val = -1*stoi(str);
                    }
                    else val = stoi(str);
                    TreeNode *leftNode = new TreeNode(val);
                    temp->left = leftNode;
                    q.push(leftNode);
                    i++;
                }
                if(levelOrder[i]=="null"){
                    temp->right = NULL;
                    i++;
                }else{
                    int val=0;
                    string str = levelOrder[i];
                    if(str[0]=='n'){
                        str.erase(str.begin()+0);
                        val = -1*stoi(str);
                    }
                    else val = stoi(str);
                    TreeNode *rightNode = new TreeNode(val);
                    temp->right = rightNode;
                    q.push(rightNode);
                    i++;
                }
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));