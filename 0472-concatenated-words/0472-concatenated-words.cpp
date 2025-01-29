class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string>dictionary(words.begin(),words.end());
        vector<string>answer;
        for(auto word:words){
            int len=word.size();
            vector<bool>dp(len+1);
            dp[0]=true;
            for(int i=1;i<=len;i++){
                for(int j=(i==len?1:0);!dp[i]&&j<i;j++){
                    dp[i]=dp[j]&&dictionary.count(word.substr(j,i-j));
                }
            }
            if(dp[len]){
                answer.push_back(word);
            }
        }
        return answer;
    }
};