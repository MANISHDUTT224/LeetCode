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
const int SHIFT=20;
const int MASK=0xFFFFF;
    int minimumOperations(TreeNode* root) {cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
        queue<TreeNode*>queue;
        queue.push(root);
        int swaps=0;
        while(!queue.empty()){
            int levelsize=queue.size();
            vector<long long>nodes(queue.size());
            for(int i=0;i<levelsize;i++){
                TreeNode* node=queue.front();
                queue.pop();
                nodes[i]=(static_cast<long long>(node->val)<<SHIFT)+i;
                if(node->left!=nullptr){
                    queue.push(node->left);
                }
                if(node->right!=nullptr){
                    queue.push(node->right);
                }
            }
            sort(nodes.begin(),nodes.end());
            for(int i=0;i<levelsize;i++){
                int origpos=static_cast<int>(nodes[i]&MASK);
                if(origpos!=i){
                    swap(nodes[i],nodes[origpos]);
                    swaps++;
                    i--;
                }
            }

        }
        return swaps;
    }
};