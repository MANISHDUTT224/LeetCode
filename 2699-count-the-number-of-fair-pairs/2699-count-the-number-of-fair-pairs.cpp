class Solution {
public:
    long long countFairPairs(vector<int>& v, int lower, int upper) {
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
        long long ans=0;
        sort(v.begin(),v.end());
        for(int i=0;i<v.size()-1;i++){
            auto up=upper_bound(v.begin()+i+1,v.end(),upper-v[i]);
            auto low=lower_bound(v.begin()+i+1,v.end(),lower-v[i]);
            ans+=(up-low);
        }
        return ans;
    }
};