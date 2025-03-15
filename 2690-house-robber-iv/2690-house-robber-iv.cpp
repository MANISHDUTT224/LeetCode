class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int minreward=1,maxreward=*max_element(nums.begin(),nums.end());
        int n=nums.size();
       
        while(minreward<maxreward){
            int midreward=(minreward+maxreward)/2;
             int totalhouses=0;
            for(int i=0;i<n;i++){
                if(nums[i]<=midreward){
                    totalhouses++;
                    i++;
                }
            }
            if(totalhouses>=k){
                maxreward=midreward;
            }
            else{
                minreward=midreward+1;
            }
        }
        return minreward;
    }
};