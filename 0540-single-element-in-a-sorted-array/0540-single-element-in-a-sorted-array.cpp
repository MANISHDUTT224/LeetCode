class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        int n=nums.size();
        int i=0,j=n-1;
        while(i<j){
            int mid=(i+j)/2;
        int num=(mid%2==0)?mid+1:mid-1;
        if(nums[mid]==nums[num]){
           i=mid+1;
        }
        else{
            j=mid;
        }
        }
        return nums[i];
    }
};