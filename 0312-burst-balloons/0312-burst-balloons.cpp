class Solution {
public:
    int solve(vector<int>&arr,vector<vector<int>>&dp,int left,int right){
        if(left>right){
            return 0;
        }
        if(dp[left][right]!=-1){
            return dp[left][right];
        }
        int maxpts=0;
        for(int i=left;i<=right;i++){
            int pts=solve(arr,dp,left,i-1)+solve(arr,dp,i+1,right)+(arr[left-1]*arr[i]*arr[right+1]);
            maxpts=max(maxpts,pts);
        }
        dp[left][right]=maxpts;
        return maxpts;
    }
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        vector<int>newnums(n+2,0);
        newnums[0]=newnums[n+1]=1;
        for(int i=0;i<n;i++){
            newnums[i+1]=nums[i];
        }
        vector<vector<int>>dp(n+2,vector<int>(n+2,-1));
        return solve(newnums,dp,1,n);
    }
};