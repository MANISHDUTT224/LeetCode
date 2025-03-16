class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cnt=0,sum=0;
        map<int,int>mp;
        mp[0]++;
        for(int num:nums){
            sum+=num;
            int res=sum-k;
            cnt+=mp[res];
            mp[sum]++;
        }
        return cnt;
    }
};