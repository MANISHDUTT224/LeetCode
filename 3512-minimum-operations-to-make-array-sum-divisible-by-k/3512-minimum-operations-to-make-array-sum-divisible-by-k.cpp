class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int sm=0;
        for(int num:nums){
            sm+=num;
        }
        return sm%k;
    }
};