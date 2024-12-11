class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
        int n=nums.size(),j=0,ans=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            while(nums[j]+2*k<nums[i]){
                j++;
            }
            ans=max(ans,i-j+1);
        }
        return ans;
    }
};