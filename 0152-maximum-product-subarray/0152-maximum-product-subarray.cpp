class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prd1=1,prd2=1;
        int maxprd=INT_MIN;
        for(int i=0;i<nums.size();i++){
            prd1*=nums[i];
            maxprd=max(prd1,maxprd);
            if(prd1==0){
                prd1=1;
            }
        }
        prd1=1;
        for(int i=nums.size()-1;i>=0;i--){
            prd1*=nums[i];
             maxprd=max(prd1,maxprd);
            if(prd1==0){
                prd1=1;
            }
        }
        return maxprd;
    }
};