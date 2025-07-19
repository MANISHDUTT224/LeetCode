class Solution {
public:
    bool isPossible(vector<int>&nums,int mid,int k){
        int sum=0,cnt=1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>mid){
                return false;
            }
            if(sum+nums[i]>mid){
                sum=nums[i];
                cnt++;
            }
            else{
                sum+=nums[i];
            }
        }
        return cnt<=k;
    }
    int splitArray(vector<int>& nums, int k) {
        int i=min(nums[0],nums[nums.size()-1]);
        int j=accumulate(nums.begin(),nums.end(),0);
        int ans=-1;
        while(i<=j){
            int mid=i+(j-i)/2;
            if(isPossible(nums,mid,k)){
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