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
    vector<int> rightSideView(TreeNode* root) {
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
        vector<int>res;
        int level=0;
        while(root){
            if(root->right){
            TreeNode *pred=root->right;
            int backdepth=1;
            while(pred->left!=nullptr && pred->left!=root){
                pred=pred->left;
                backdepth++;
            }
            if(pred->left==nullptr){
                if(res.size()==level){
                    res.push_back(root->val);
                }
                pred->left=root;
                root=root->right;
                level++;
            }
            else{
                pred->left=nullptr;
                root=root->left;
                level-=backdepth;
            }
        }

        
        else{
            if(res.size()==level){
                res.push_back(root->val);
            }
            root=root->left;
            level++;

        }
    }
        return res;
    }
};