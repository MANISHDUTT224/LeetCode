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
    bool isBalanced(TreeNode* root) {
        return dfs(root).first;
    }
    pair<bool,int>dfs(TreeNode* root){
        if(!root){
            return {true,0};
        }
        auto [LeftBalanced,leftHeight]=dfs(root->left);
        auto [RightBalanced,rightHeight]=dfs(root->right);
        bool isBalanced= LeftBalanced && RightBalanced && (abs(leftHeight-rightHeight)<=1);
        return {isBalanced,1+max(leftHeight,rightHeight)};
    }
};