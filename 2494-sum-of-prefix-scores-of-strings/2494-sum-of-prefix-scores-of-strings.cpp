class TrieNode{
    public:
    unordered_map<char,TrieNode *>children;
    int pc;
    TrieNode(){
        pc=0;
    }
};
class Trie{
public:
    TrieNode *root;
    Trie(){
        root=new TrieNode();
    }
    void insert(const string &word){
        TrieNode *node=root;
        for(char c:word){
            if(node->children.find(c)==node->children.end()){
                node->children[c]=new TrieNode();
            }
            node=node->children[c];
            node->pc++;
        }
    }
    int getprefixscore(const string &word){
        TrieNode *node=root;
        int sc=0;
        for(char c:word){
            node=node->children[c];
            sc+=node->pc;
        }
        return sc;
    }

};
class Solution {
public:

    vector<int> sumPrefixScores(vector<string>& words) {
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
        Trie trie;
        vector<int> result;
        for(auto it:words){
            trie.insert(it);
        }
        for(auto it1:words){
            result.push_back(trie.getprefixscore(it1));
        }
        return result;
    }
};