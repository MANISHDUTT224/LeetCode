class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        int s=0;
        for(int r:rods){
            s+=r;

        }
        int dp[s+1];
        dp[0]=0;
        for(int i=1;i<=s;i++){
            dp[i]=-1;
        }
        for(int r:rods){
            int newdp[s+1];
            copy(dp,dp+(s+1),newdp);
            for(int i=0;i<=s-r;i++){
                if(newdp[i]<0){
                    continue;
                }
                dp[i+r]=max(dp[i+r],newdp[i]);
                dp[abs(i-r)]=max(dp[abs(i-r)],min(i,r)+newdp[i]);
            }
        }
        return dp[0];
    }
};