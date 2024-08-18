class Solution {
public:
    int nthUglyNumber(int &n) {
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
        vector<int> dp(n,0);
        int i=0,j=0,k=0;
        dp[0]=1;
        for(int l=1;l<n;l++){
            dp[l]=min({dp[i]*2,dp[j]*3,dp[k]*5});
            if(dp[l]==dp[i]*2){
                i++;
            }
            if(dp[l]==dp[j]*3){
                j++;
            }
            if(dp[l]==dp[k]*5){
                k++;
            }
        }
        return dp[n-1];
    }
};