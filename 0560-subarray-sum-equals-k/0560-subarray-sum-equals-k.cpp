class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cnt=0,sum=0;
        map<int,int>mp;
        mp[0]++;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            int rem=sum-k;
            if(mp.find(rem)!=mp.end()){
                cnt+=mp[rem];
            }
            mp[sum]++;
        }
        return cnt;
    }
};