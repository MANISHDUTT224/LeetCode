class Solution {
public:
    int countOfPairs(vector<int>& nums) {
        int n=nums.size(),m=1001;
        vector<int>dp(m,1);
        const int mod=1e9+7;
        for(int i=1;i<n;i++){
            int d=max(0,nums[i]-nums[i-1]);
            vector<int>dp2(m,0);
            for(int j=d;j<nums[i]+1;j++){
                dp2[j]=((j>0?dp2[j-1]:0)+dp[j-d])%mod;
            }
            swap(dp,dp2);
        }
        int res=0;
        for(int j=0;j<=nums[n-1];j++){
            res=(res+dp[j])%mod;
        }
        return res;
    }
};