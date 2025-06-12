class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
    int diff=abs(nums[nums.size()-1]-nums[0]);
    for(int i=0;i<nums.size()-1;i++){
        diff=max(diff,abs(nums[i+1]-nums[i]));
    }
    return diff;
    }
};