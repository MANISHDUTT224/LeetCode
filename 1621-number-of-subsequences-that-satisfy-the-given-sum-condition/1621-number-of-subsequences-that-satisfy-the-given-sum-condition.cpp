class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int mod=1000000007,n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int>power(n,1);
        for(int i=1;i<n;i++){
            power[i]=(power[i-1]*2)%mod;
        }
        int l=0,r=n-1;
        int result=0;
        while(l<=r){
            if(nums[l]+nums[r]<=target){
                result=(result+(power[r-l]))%mod;
                ++l;
            }
            else{
                --r;
            }
        }
        return result;
    }
};