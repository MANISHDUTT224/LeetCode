class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>freq(n+1,0);
        for(int num:nums){
            freq[min(n,num)]++;
        }

        int num_greater=0;
        for(int i=n;i>0;i--){
            num_greater+=freq[i];
            if(i==num_greater){
                return i;
            }
        }
        return -1;
    }
};