class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        vector<int>dp(nums.size(),-1);
        dp[0]=0;
        for(int i=0;i<nums.size();i++){
            if(i>0 && dp[i]<=0){
                continue;
            }
            for(int j=i+1;j<nums.size();j++){
                if(abs(nums[i]-nums[j])<=abs(target)){
                    dp[j]=max(dp[j],dp[i]+1);
                }
            }
        }
        return dp[nums.size()-1];


    }
};