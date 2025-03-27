class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n=nums.size();
      int x=nums[0],count=0,xcount=0;
      for(auto num:nums){
        if(num==x){
            count++;
        }
        else{
            count--;
        }
        if(count==0){
            x=num;
            count=1;
        }
      }
      for(auto num: nums){
        if(num==x){
            xcount++;
        }
      }
      count=0;
      for(int i=0;i<n;i++){
        if(nums[i]==x){
            count++;
        }
        int remcount=xcount-count;
        if(count*2>i+1 && remcount*2>n-i-1){
            return i;
        }
      }
      return -1;
    }
};