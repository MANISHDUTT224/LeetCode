class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
        int n=nums.size();
        vector<int>bitcount(32,0);
        int left=0,currentor=0;
        int minlength=INT_MAX;
        for(int right=0;right<n;right++){
            currentor|=nums[right];
            for(int i=0;i<32;i++){
                if(nums[right] & (1<<i)){
                    bitcount[i]++;
                }
            }
            while(left<=right && currentor>=k){
                minlength=min(minlength,right-left+1);
                int updatedor=0;
                for(int i=0;i<32;i++){
                    if(nums[left] & (1<<i)){
                        bitcount[i]--;
                    }
                    if(bitcount[i]>0){
                        updatedor|=(1<<i);
                    }
                }
                currentor=updatedor;
                left++;
            }
        }
        return minlength==INT_MAX?-1:minlength;

    }
};