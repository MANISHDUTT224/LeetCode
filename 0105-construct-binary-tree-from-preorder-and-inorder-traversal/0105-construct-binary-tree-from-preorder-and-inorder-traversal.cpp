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
    unordered_map<int,int>mapping;
    int preorderindex;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        mapping.clear();
        for(int i=0;i<inorder.size();i++){
            mapping[inorder[i]]=i;
        }
        preorderindex=0;
        return build(preorder,0,inorder.size()-1);
    }
    TreeNode* build(vector<int>&preorder,int start,int end){
        if(start>end){
            return nullptr;
        }
        int rootval=preorder[preorderindex++];
        TreeNode* root=new TreeNode(rootval);
        int mid=mapping[rootval];
        root->left=build(preorder,start,mid-1);
        root->right=build(preorder,mid+1,end);
        return root; 
    }
};