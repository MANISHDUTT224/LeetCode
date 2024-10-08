class Solution {
public:
    int uniquePaths(int m, int n) {
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
        if (m==1 || n==1){
            return 1;
        }
        vector<int> dp(n+1,1);
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[j]+=dp[j-1];
            }
        }
        return dp[n-1];
    }
};