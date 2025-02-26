class Solution {
public:
    int kInversePairs(int n, int k) {
        const int MOD=1e9+7;
        vector<int>prev(k+1,0);
        vector<int>cur(k+1,0);
        prev[0]=cur[0]=1;
        for(int N=1;N<=n;N++){
            for(int K=0;K<=k;K++){
                cur[K]=(prev[K]+(K>0?cur[K-1]:0))%MOD;
                cur[K]=(cur[K]+MOD-(K>=N?prev[K-N]:0))%MOD;
            }
            prev=cur;
        }
        return cur[k];
    }
};