/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void post(Node *root,vector<int> &result){
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
        if(root==nullptr){
            return;
        }
        for(Node *child:root->children){
            post(child,result);
        }
        result.push_back(root->val);
    }
    vector<int> postorder(Node* root) {
        vector<int>result;
        post(root,result);
        return result;
    }
};