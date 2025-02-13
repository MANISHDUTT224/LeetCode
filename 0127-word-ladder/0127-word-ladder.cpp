class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st;
        for(auto word:wordList){
            st.insert(word);
        }
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        while(!q.empty()){
            auto[word,len]=q.front();
            q.pop();
            for(int i=0;i<word.size();i++){
                string temp=word;
                if(word==endWord){
                    return len;
                }
                for(char c='a';c<='z';c++){
                    word[i]=c;
                    if(st.find(word)!=st.end()){
                        q.push({word,len+1});
                        st.erase(word);
                    }
                }
                word=temp;
            }
        }
        return 0;
    }
};