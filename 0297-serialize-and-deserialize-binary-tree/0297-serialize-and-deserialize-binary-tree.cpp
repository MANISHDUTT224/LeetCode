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
        
        if(!root){
            return "";
        }
        queue<TreeNode*>q;
        q.push(root);
        string res="";
        res+=(to_string(root->val)+",");
        while(!q.empty()){
            TreeNode* curnode=q.front();
            q.pop();
            
            if(curnode->left==nullptr){
                res+="#,";
            }
            else{
                res+=(to_string(curnode->left->val))+",";
                q.push(curnode->left);
            }
            if(curnode->right==nullptr){
                res+="#,";
            }
            else{
                res+=(to_string(curnode->right->val))+",";
                q.push(curnode->right);
            }
        }
        cout<<res;
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0){
            return nullptr;
        }
        stringstream s(data);
        string str;
        getline(s,str,',');
        queue<TreeNode*>q;
        TreeNode* root=new TreeNode(stoi(str));
        q.push(root);
        while(!q.empty()){
            TreeNode* curnode=q.front();
            q.pop();
            getline(s,str,',');
            if(str=="#"){
                curnode->left=NULL;
            }
            else{
                TreeNode *leftnode=new TreeNode(stoi(str));
                curnode->left=leftnode;
                q.push(leftnode);
            }
            getline(s,str,',');
            if(str=="#"){
                curnode->right=NULL;
            }
            else{
                TreeNode *rightnode=new TreeNode(stoi(str));
                curnode->right=rightnode;
                q.push(rightnode);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));