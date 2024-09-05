class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
        const int m=rolls.size();
        const int srolls=accumulate(rolls.begin(),rolls.end(),0);
        const int total=(n+m)*mean,miss=total-srolls;
        if(miss>6*n || miss<n){
            return {};
        }
        auto [q,r]=div(miss,n);
        vector<int> ans(n,q);
        fill(ans.begin(),ans.begin()+r,q+1);
        return ans;
    }
};