class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>result;
        int prd=1;int zp=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
               zp++;
                
            }
            else{
            prd*=nums[i];
            }
        }
        for(int i=0;i<nums.size();i++){
            if(zp){
                if(nums[i]==0&&zp==1){
                    result.push_back(prd);
                }
                else{
                    result.push_back(0);
                }
            }
            else{
                result.push_back(prd/nums[i]);
            }
        }
        return result;
    }
};