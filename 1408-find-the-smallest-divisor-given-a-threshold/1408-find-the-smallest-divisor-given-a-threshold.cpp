class Solution {
public:
    int sumByD(int mid,vector<int>&nums){
        int  total=0;
        for(int i=0;i<nums.size();i++){
            total+=ceil((double)nums[i]/(double)mid);
        }
        return total;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int i=1,j=*max_element(nums.begin(),nums.end()),ans;
        while(i<=j){
            int mid=(i+j)/2;
            if(sumByD(mid,nums)<=threshold){
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