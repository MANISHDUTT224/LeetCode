class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        int maxi=*max_element(nums.begin(),nums.end());
        long long ans=0,s=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==maxi){
                k--;
            }
            while(!k){
                if(nums[s]==maxi){
                    k++;
                }
                s++;
            }
            ans+=s;
        }
        return ans;
    }
};