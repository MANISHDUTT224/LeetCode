class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n=nums.size();
        vector<int> lis(n,1),lds(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                lis[i]=max(lis[i],lis[j]+1);
                }
            }
        }
        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>=i;j--){
                if(nums[i]>nums[j]){
                    lds[i]=max(lds[i],lds[j]+1);
                }
            }
        }
        int maxlen=0;
        for(int i=0;i<n-1;i++){
            if(lds[i]>1 && lis[i]>1){
                maxlen=max(maxlen,lds[i]+lis[i]-1);
            }
        }
        return abs(maxlen-n);
    }
};