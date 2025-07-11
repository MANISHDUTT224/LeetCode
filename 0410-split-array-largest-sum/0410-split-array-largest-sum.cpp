class Solution {
public:
    bool Possible(vector<int>&nums,int mid,int k){
        int count=1,sm=0;
        for(int i=0;i<nums.size();i++){
            if(sm+nums[i]>mid){
                sm=nums[i];
                count++;
            }
            else{
                sm+=nums[i];
            }
        }
        return count<=k;
    }
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        int i=min(nums[0],nums[n-1]);
        int j=accumulate(nums.begin(),nums.end(),0);
        int ans=-1;
        while(i<=j){
            int mid=(i+j)/2;
            if(Possible(nums,mid,k)){
                ans=mid;
                j=mid-1;
            }
            else{
                i=mid+1;
            }
        }
        return ans;
    }
};