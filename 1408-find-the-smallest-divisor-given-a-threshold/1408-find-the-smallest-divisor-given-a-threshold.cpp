class Solution {
public:
    long sumByD(vector<int>&nums,int mid){
        int total=0;
        for(int i=0;i<nums.size();i++){
            total+=ceil((double)nums[i]/(double)mid);
        }
        return total;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int i=1,j=*max_element(nums.begin(),nums.end());
        int ans=-1;
        while(i<=j){
            int mid=(i+j)/2;
            if(sumByD(nums,mid)<=threshold){
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