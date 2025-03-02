class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n=satisfaction.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        int mx=0;
        sort(satisfaction.begin(),satisfaction.end());
        for(int i=1;i<=n;i++){
            for(int j=1;j<=i;j++){
                dp[i][j]=dp[i-1][j-1]+satisfaction[i-1]*j;
                mx=max(mx,dp[i][j]);
            }
        }
        return mx;
    }
};