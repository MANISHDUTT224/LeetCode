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
    void inorder(TreeNode* root){
        if(root==nullptr){
            return;
        }
        inorder(root->left);
        v.push_back(root);
        inorder(root->right);
    }
    TreeNode* SortedtoBST(int l,int r){
        if(l>r){
            return nullptr;
        }
        int mid=(l+r)/2;
        TreeNode*  root=v[mid];
        root->left=SortedtoBST(l,mid-1);
        root->right=SortedtoBST(mid+1,r);
        return root;
    }
public:
    vector<TreeNode*> v;
    TreeNode* balanceBST(TreeNode* root) {
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
        inorder(root);
        return SortedtoBST(0,v.size()-1);
    }
};