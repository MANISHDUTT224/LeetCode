class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        int mini=-1,maxi=-1,ci=-1;
        long long int ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<minK || nums[i]>maxK){
                ci=i;
            }

            if(nums[i]==minK){
                mini=i;
            }
            if(nums[i]==maxK){
                maxi=i;
            }
            int small=min(mini,maxi);
            int temp=small-ci;
            ans+=(temp<=0)?0:temp;
        }
        return ans;
    }
};