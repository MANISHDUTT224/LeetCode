class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
        int n=nums.size();
        vector<int>prefixsum(n+1,0);
        for(int i=1;i<=n;i++){
            prefixsum[i]=prefixsum[i-1]+nums[i-1];
        }
        vector<vector<int>>bestsum(4,vector<int>(n+1,0));
        vector<vector<int>>bestindex(4,vector<int>(n+1,0));
        for(int subarraycount=1;subarraycount<=3;subarraycount++){
            for(int endindex=k*subarraycount;endindex<=n;endindex++){
                int currentsum=prefixsum[endindex]-prefixsum[endindex-k]+bestsum[subarraycount-1][endindex-k];
                if(currentsum>bestsum[subarraycount][endindex-1]){
                    bestsum[subarraycount][endindex]=currentsum;
                    bestindex[subarraycount][endindex]=endindex-k;
                }
                else{
                    bestsum[subarraycount][endindex]=bestsum[subarraycount][endindex-1];
                    bestindex[subarraycount][endindex]=bestindex[subarraycount][endindex-1];
                }
            }
        }
        vector<int>result(3,0);
        int currentend=n;
        for(int i=3;i>=1;i--){
            result[i-1]=bestindex[i][currentend];
            currentend=result[i-1];
        }
        return result;
    }
};