class Solution {
public:
    bool isSubset(vector<int>&nums,int sum){
        int s=nums.size();
        vector<vector<bool>>dp(s+1,vector<bool>(sum+1,false));
        for(int i=0;i<s;i++){
            dp[i][0]=true;
        }
        for(int i=1;i<=s;i++){
            for(int j=1;j<=sum;j++){
                if(nums[i-1]<=j){
                    dp[i][j]=dp[i-1][j]||dp[i-1][j-nums[i-1]];
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[s][sum];
    }
    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%2==0){
            return isSubset(nums,sum/2);
        }
        return false;
    }
};