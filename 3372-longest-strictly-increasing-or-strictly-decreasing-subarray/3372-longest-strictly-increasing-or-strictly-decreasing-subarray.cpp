class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size();
        int inclen=1,declen=1;
        int maxlen=1;
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
                inclen++;  
            }
            else{   
                inclen=1;
            }
            maxlen=max(maxlen,inclen);
        }
        
        inclen=1;
        for(int i=1;i<n;i++){
             if(nums[i]<nums[i-1]){
                inclen++;  
            }
            else{   
                inclen=1;
            }
             maxlen=max(maxlen,inclen);
        }
        
        return maxlen;
    }
};