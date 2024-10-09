class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        map<int,int>mp;
        for(int i:nums){
            mp[i]++;
        }
        int sum=0;
        for(auto it:mp){
            if(it.second==1){
                sum+=it.first;
            }
        }
        return sum;
    }
};