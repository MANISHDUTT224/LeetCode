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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode *>nodemap;
        for(vector<int> &desc:descriptions){
            int pval=desc[0];
            int cval=desc[1];
            int isleft=desc[2];
            TreeNode *parent=nodemap.count(pval)?nodemap[pval]:(nodemap[pval]=new TreeNode(pval));
            TreeNode *child=nodemap.count(cval)?nodemap[cval]:(nodemap[cval]=new TreeNode(cval));
            if(isleft){
                parent->left=child;
            }
            else{
                parent->right=child;
            }
        }
            for(vector<int> &de:descriptions){
                nodemap.erase(de.at(1));
            }
        
        return nodemap.begin()->second;
        
    }
};