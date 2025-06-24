class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zerocount=0,prd=1;
        for(int num:nums){
            if(num!=0){
            prd*=num;
            }
            else{
                zerocount++;
            }
        }
        vector<int>ans(nums.size(),0);
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0 && zerocount==1){
                ans[i]=prd;
            }
            else if(zerocount>1){
                ans[i]=0;
            }
            else if(zerocount==0){
                ans[i]=prd/nums[i];
            }
        }
        return ans;
    }
};