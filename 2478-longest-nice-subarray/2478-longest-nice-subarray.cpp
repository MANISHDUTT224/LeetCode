class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int maxlen=0,left=0,curbits=0,n=nums.size();
        for(int right=0;right<n;right++){
            while((curbits & nums[right])!=0){
                curbits^=nums[left];
                left++;
            }
            curbits|=nums[right];
            maxlen=max(maxlen,right-left+1);
        }

        return maxlen;
    }
};