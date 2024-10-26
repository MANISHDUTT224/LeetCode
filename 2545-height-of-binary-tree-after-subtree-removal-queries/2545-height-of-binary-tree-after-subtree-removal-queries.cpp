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
    int currentMaxheight=0;
    int maxheightafterremoval[100001];
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        traverseleftoright(root,0);
        currentMaxheight=0;
        traverserightoleft(root,0);
        int querylen=queries.size();
        vector<int> queryres(querylen);
        for(int i=0;i<querylen;i++){
            queryres[i]=maxheightafterremoval[queries[i]];
        }
        return queryres;
    }
    void traverseleftoright(TreeNode *node,int currentHeight){
        if(node==nullptr){
            return;
        }
        maxheightafterremoval[node->val]=currentMaxheight;
        currentMaxheight=max(currentHeight,currentMaxheight);
        traverseleftoright(node->left,currentHeight+1);
        traverseleftoright(node->right,currentHeight+1);
    }
    void traverserightoleft(TreeNode *node,int currentHeight){
        if(node==nullptr){
            return;
        }
        maxheightafterremoval[node->val]=max(maxheightafterremoval[node->val],currentMaxheight);
        currentMaxheight=max(currentHeight,currentMaxheight);
        traverserightoleft(node->right,currentHeight+1);
        traverserightoleft(node->left,currentHeight+1);
    }

};