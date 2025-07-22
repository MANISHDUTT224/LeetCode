class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int i=0,j=n-1;
        while(i<j){
            int mid=i+(j-i)/2;
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