class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        if(nums.size()<=k){
            return (double)accumulate(nums.begin(),nums.end(),0)/(double)(k);
        }
        double sum=0;
       for(int i=0;i<k;i++){
        sum+=nums[i];
       }
       int n=nums.size();
       double avg=sum/(double)k;
       for(int i=1;i<=n-k;i++){
        sum-=nums[i-1];
        sum+=nums[i+(k-1)];
        avg=max(avg,(double)(sum)/(double)(k));
       }
       return avg;
    }
};