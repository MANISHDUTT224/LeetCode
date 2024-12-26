class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
        int totalsum=accumulate(nums.begin(),nums.end(),0);
        vector<int>dp(2*totalsum+1,0);
        dp[nums[0]+totalsum]=1;
        dp[-nums[0]+totalsum]+=1;
        for(int i=1;i<nums.size();i++){
            vector<int>next(2*totalsum+1,0);
           
            for(int sum=-totalsum;sum<=totalsum;sum++){
                 if(dp[sum+totalsum]>0){
                next[sum+totalsum+nums[i]]+=dp[sum+totalsum];
                next[sum+totalsum-nums[i]]+=dp[sum+totalsum];
                 }
            }
            dp=next;
        }
        return abs(target)>totalsum?0:dp[target+totalsum];
    }
};