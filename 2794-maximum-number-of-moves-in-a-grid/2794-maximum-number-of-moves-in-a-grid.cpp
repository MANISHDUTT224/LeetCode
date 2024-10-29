class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<int>dp(m);
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
        int res=0;
        for(int j=1;j<n;j++){
            bool found=false;
            int leftop=0;
            for(int i=0;i<m;i++){
                int nxtleftop=dp[i];

                int cur=-1;
                if(i-1>=0 && leftop!=-1 && grid[i][j]>grid[i-1][j-1]){
                    cur=max(cur,leftop+1);
                }
                if(dp[i]!=-1 && grid[i][j]>grid[i][j-1]){
                    cur=max(cur,dp[i]+1);
                }
                if(i+1<m && dp[i+1]!=-1 && grid[i+1][j-1]<grid[i][j]){
                    cur=max(dp[i+1]+1,cur);
                }
                dp[i]=cur;
                leftop=nxtleftop;
                found=found||(dp[i]!=-1);

            }
            if(!found){
                break;
            }
            res=j;
        }
        return res;
    }
};