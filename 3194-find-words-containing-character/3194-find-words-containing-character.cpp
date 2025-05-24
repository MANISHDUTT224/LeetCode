class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int>ans;
        int c=0;
        for(auto word:words){
            for(int i=0;i<word.size();i++){
                if(word[i]==x){
                    ans.push_back(c);
                    break;
                }
            }
            c++;
        }
        return ans;
    }
};