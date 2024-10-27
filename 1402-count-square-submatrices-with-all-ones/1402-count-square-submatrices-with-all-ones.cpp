class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
        int ans=0;
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++){
            dp[i][0]=matrix[i][0];
            ans+=dp[i][0];
        }
        
        for(int j=1;j<m;j++){
            dp[0][j]=matrix[0][j];
            ans+=dp[0][j];
        }
    
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(matrix[i][j]==1){
                    dp[i][j]=1+min({dp[i-1][j],dp[i-1][j-1],dp[i][j-1]});
                }
            ans+=dp[i][j];
            }
            
        }
        return ans;
    }
};