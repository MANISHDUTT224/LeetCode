class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
        sort(happiness.begin(),happiness.end());
        reverse(happiness.begin(),happiness.end());
        long res=0;
        int i=0;
        while(k--){
            happiness[i]=max(happiness[i]-i,0);
            res+=happiness[i++];
        }
        return res;
        
    }
};