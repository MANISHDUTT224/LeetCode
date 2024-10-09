class Solution {
public:
    int majorityElement(vector<int>& nums) {
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
        unordered_map<int,int>mp;
        for(int i:nums){
            mp[i]++;
        }
        int n=nums.size();
        for(auto it:mp){
            if(it.second>n/2){
                return it.first;
            }
        }
        return 0;
    }
    
};