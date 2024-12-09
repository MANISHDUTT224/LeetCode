class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
        int n=nums.size();
        vector<int>prefix(n,0);
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1];
            if((nums[i]%2==0 && nums[i-1]%2==0)||(nums[i]%2!=0 && nums[i-1]%2!=0)){
                prefix[i]++;
            }
        }
        vector<bool>ans;
        for(auto& q:queries){
            int left=q[0],right=q[1];
            int splcount=prefix[right]-(left>0?prefix[left]:0);
            ans.push_back(splcount==0);
        }
        return ans;
    }
};