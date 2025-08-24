class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        int n=nums.size();
        int i=0,j=0;
        int c0=0,len=INT_MIN;
        while(j<n){
           
            if(nums[j]==0)
                c0++;
            while(c0>1){
                if(nums[i]==0)
                    c0--;
                i++;
            }

            if(c0<=1){
                len=max(len,j-i+1);
            }

            j++;
        }

        return len-1;


    }
};