class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        while(nums[0]!=nums[nums[0]]){
            ios::sync_with_stdio(false);
            cin.tie(0);
            swap(nums[0],nums[nums[0]]);
        }
        return nums[0];
        
    }
};