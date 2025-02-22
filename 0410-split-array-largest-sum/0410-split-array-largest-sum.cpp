class Solution {
public:
    bool possible(vector<int>arr,int n,int k,int mid){
        int cnt=1;
        int sum=0;
        for(int i=0;i<n;i++){
            if(arr[i]>mid){
               return false;
            }
            if(sum+arr[i]>mid){
                cnt++;
                sum=arr[i];
            }
            else{
                sum+=arr[i];
            }
        }
        return cnt<=k;
    }
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0);
        int low=min(nums[0],nums[n-1]);
        int high=sum;
        while(low<=high){
            int mid=(low+high)/2;
            if(possible(nums,n,k,mid)){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};