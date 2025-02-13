class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<int>dp(text1.size(),0);
        for(char c:text2){
            int len=0;
            int maxlen=0;
            for(int i=0;i<text1.size();i++){
                if(len<dp[i]){
                    len=dp[i];
                }
                else if(c==text1[i]){
                    dp[i]=len+1;
                     maxlen=max(maxlen,len);
                }
            }
        }
        return dp[text1.size()-1];
    }
};