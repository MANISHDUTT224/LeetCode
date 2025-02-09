class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long n=nums.size();
        long long totalpairs=n*(n-1)/2;
        long long cnt=0;
        unordered_map<int,int>diffcount;
        for(int i=0;i<n;i++){
            int diff=nums[i]-i;
            cnt+=diffcount[diff];
            diffcount[diff]++;
        }
        return totalpairs-cnt;
    }
};