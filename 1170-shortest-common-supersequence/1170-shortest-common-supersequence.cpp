class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n=str1.size();
        int m=str2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        int row=n,col=m;
        for(int i=0;i<=row;i++){
            dp[i][0]=i;
        }
        for(int j=0;j<=col;j++){
            dp[0][j]=j;
        }
        for(int i=1;i<=row;i++){
            for(int j=1;j<=col;j++){
                if(str1[i-1]==str2[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else{
                    dp[i][j]=min(dp[i-1][j],dp[i][j-1])+1;
                }
            }
        }
        string supersequence="";
         row=n,col=m;
        while(row>0 && col>0){
            if(str1[row-1]==str2[col-1]){
                supersequence+=str1[row-1];
                row--;
                col--;
            }
            else if(dp[row-1][col]<dp[row][col-1]){
                supersequence+=str1[--row];
            }
            else{
                supersequence+=str2[--col];
            }
        }
        while(row>0){
            supersequence+=str1[row-1];
            row--;
        }
        while(col>0){
            supersequence+=str2[col-1];
            col--;
        }
        reverse(supersequence.begin(),supersequence.end());
        return supersequence;
    }
};