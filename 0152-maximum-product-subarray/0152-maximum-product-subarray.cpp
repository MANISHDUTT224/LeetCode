class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prd=1,maxprd=INT_MIN;
        for(int num:nums){
            prd*=num;
             maxprd=max(maxprd,prd);
            if(prd==0){
                prd=1;
            }
           
        }
        prd=1;
        for(int i=nums.size()-1;i>=0;i--){
            prd*=nums[i];
            maxprd=max(maxprd,prd);
            if(prd==0){
                prd=1;
            }
            
        }
        return maxprd;
    }
};