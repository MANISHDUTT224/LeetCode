class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
        sort(nums.begin(),nums.end());
        int res=-1;
        map<int,int> mp;
        for(int num:nums){
            int s=sqrt(num);
            if(s*s==num && mp.find(s)!=mp.end()){
                mp[num]=mp[s]+1;
                res=max(res,mp[num]);
            }
            else{
                mp[num]=1;
            }
        }
        return res;
    }
};