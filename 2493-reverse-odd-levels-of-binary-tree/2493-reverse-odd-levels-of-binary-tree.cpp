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
void traverseDFS(TreeNode* leftchild,TreeNode* rightchild,int level){
    if(leftchild==nullptr || rightchild==nullptr){
        return;
    }
    if(level%2==0){

        int temp=leftchild->val;
        leftchild->val=rightchild->val;
        rightchild->val=temp;
    }
    traverseDFS(leftchild->left,rightchild->right,level+1);
    traverseDFS(leftchild->right,rightchild->left,level+1);
}
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
        traverseDFS(root->left,root->right,0);
        return root;
    }
};