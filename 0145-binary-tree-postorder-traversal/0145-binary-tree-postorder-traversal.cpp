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
    void postord(TreeNode *root,vector<int> &ans){
        if(root==nullptr){
            return;
        }
        postord(root->left,ans);
        postord(root->right,ans);
        ans.push_back(root->val);
        
    }

    vector<int> postorderTraversal(TreeNode* root) {
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
        vector<int> ans;
        postord(root,ans);
        return ans;
    }
};