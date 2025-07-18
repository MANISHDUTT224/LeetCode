class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size(),0);
        dp[0]=nums[0];
        int n=nums.size();
        if(n==1){
            return dp[0];
        }
        dp[1]=max(nums[0],nums[1]);
        for(int i=2;i<nums.size();i++){
            dp[i]=max(dp[i-1],nums[i]+dp[i-2]);
        }
        return dp[n-1];
    }
};