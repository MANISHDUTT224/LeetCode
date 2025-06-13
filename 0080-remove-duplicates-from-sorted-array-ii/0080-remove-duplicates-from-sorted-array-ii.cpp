class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        map<int,int>mp;
        int k=0;
        for(auto num:nums){
            mp[num]++;
            if(mp[num]<=2){
                nums[k]=num;
                k++;
            }
        }
        return k;

    }
};