class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<long>dp(amount+1,amount+1);
        dp[0]=0;
        for(int coin:coins){
            for(int j=coin;j<=amount;j++){
                dp[j]=min(dp[j-coin]+1,dp[j]);
            }
        }
        if(dp[dp.size()-1]==amount+1){
            return -1;
        }
        return dp[dp.size()-1];
    }
};