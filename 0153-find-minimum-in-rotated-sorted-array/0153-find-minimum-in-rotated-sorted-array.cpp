class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int ans=INT_MAX;
        int i=0,j=n-1;
        while(i<=j){
            int mid=i+(j-i)/2;
            if(nums[i]<=nums[j]){
                ans=min(ans,nums[i]);
                return ans;
            }
            if(nums[i]<=nums[mid]){
                ans=min(nums[i],ans);
                i=mid+1;
            }
            else if(nums[mid]<=nums[j]){
                ans=min(nums[mid],ans);
                j=mid-1;
            }
        }
        return ans;
    }
};