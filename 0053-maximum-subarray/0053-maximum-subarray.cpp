class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       if(nums.size()==1){
        return nums[0];
       }
        int sum=0,maxsum=INT_MIN;
        for(int i=0;i<nums.size();i++){
        sum+=nums[i];
            maxsum=max(maxsum,sum);
           if(sum<0){
            sum=0;
           }
        }

        return maxsum;
    }
};