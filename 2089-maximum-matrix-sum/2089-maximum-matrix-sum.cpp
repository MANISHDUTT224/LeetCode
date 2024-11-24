class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
        int minabs=INT_MAX;
        int cntneg=0;
        long long sum=0;
        for(auto it:matrix)
        {
            for(auto x:it){
                minabs=min(minabs,abs(x));
                if(x<0){
                    sum-=x;
                    cntneg++;
                }
                else{
                    sum+=x;
                }
            }
        }
        return (cntneg&1)?sum-2*minabs:sum;
    }
};