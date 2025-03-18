class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int ans=INT_MAX;
        int i=0,j=nums.size()-1;
        while(i<=j){
            int mid=(i+j)/2;
            if(nums[i]<=nums[j]){
                ans=min(ans,nums[i]);
                break;
            }
            if(nums[i]<=nums[mid]){
                ans=min(nums[i],ans);
                i=mid+1;
            }
            else{
                ans=min(nums[mid],ans);
                j=mid-1;
            }
        }
        return ans;
    }
};