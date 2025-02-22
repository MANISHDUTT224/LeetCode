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
    TreeNode* recoverFromPreorder(string traversal) {
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
        int index=0;
        return traverse(traversal,index,0);
    }
    TreeNode* traverse(const string& traversal,int& index,int depth){
        if(index>=traversal.size()){
            return nullptr;
        }
        int dashcount=0;
        while(index+dashcount<traversal.size() && traversal[index+dashcount]=='-'){
            dashcount++;
        }
         if(dashcount!=depth){
            return nullptr;
        }
        index+=dashcount;
       
        int value=0;
        while(index<traversal.size() && isdigit(traversal[index])){
            value=value*10+(traversal[index]-'0');
            index++;
        }
        TreeNode* node=new TreeNode(value);
        node->left=traverse(traversal,index,depth+1);
        node->right=traverse(traversal,index,depth+1);
        return node;
    }
};