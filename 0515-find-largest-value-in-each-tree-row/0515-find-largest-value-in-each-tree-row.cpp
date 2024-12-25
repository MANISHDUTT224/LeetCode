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
    vector<int> largestValues(TreeNode* root) {
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
        if(root==nullptr){
            return vector<int>{};
        }
        queue<TreeNode*>queue;
        vector<int>ans;
        queue.push(root);
        while(!queue.empty()){
            int curmax=INT_MIN,curlen=queue.size();
            for(int i=0;i<curlen;i++){
                TreeNode *node=queue.front();
                queue.pop();
                curmax=max(curmax,node->val);
                if(node->left){
                    queue.push(node->left);
                }
                if(node->right){
                    queue.push(node->right);
                }
            }
            ans.push_back(curmax);
        }
        return ans;
    }
};