class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int n=nums.size();
        long long res=0;
        int prefix=0;
        unordered_map<int,int>cnt;
        cnt[0]=1;
        for(int i=0;i<n;i++){
            prefix+=nums[i]%modulo==k;
            res+=cnt[(prefix-k+modulo)%modulo];
            cnt[prefix%modulo]++;
        }
        return res;
    }
};