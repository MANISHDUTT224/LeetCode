class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size();
        int inclen=1,declen=1;
        int maxlen=1;
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
                inclen++;
                declen=1;  
            }
            else if(nums[i]<nums[i-1]){
                declen++;
                inclen=1;
            }
            else{   
                inclen=1;
                declen=1;
            }
            maxlen=max(maxlen,max(inclen,declen));
        }
        return maxlen;
    }
};