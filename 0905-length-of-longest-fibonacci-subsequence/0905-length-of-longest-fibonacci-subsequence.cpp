class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int dp[1000][1000];
        const int n=arr.size();
        fill(&dp[0][0],&dp[0][0]+n*1000,2);
        unordered_map<int,int>mp;
        mp.reserve(n);
        for(int i=0;i<n;i++){
            mp[arr[i]]=i;
        }
        int ans=0;
        for(int i=1;i<n-1;i++){
            int f1=arr[i];
            for(int j=i+1;j<n;j++){
                int f2=arr[j];
                int f0=f2-f1;
                if(f0>=f1){
                    break;
                }
                if(mp.count(f0)){
                    int count=mp[f0];
                    dp[i][j]=dp[count][i]+1;
                }
                ans=max(ans,dp[i][j]);
            }
        }
        return ans>2?ans:0;
    }
};