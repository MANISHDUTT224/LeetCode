class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int prefixSum=0,maxPrefixSum=0,minPrefixSum=0;
        for(int num:nums){
            prefixSum+=num;
            minPrefixSum=min(minPrefixSum,prefixSum);
            maxPrefixSum=max(maxPrefixSum,prefixSum);
        }
        return maxPrefixSum-minPrefixSum;
    }
};