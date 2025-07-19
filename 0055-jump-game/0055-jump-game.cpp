class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size(),mx=0;
        for(int i=0;i<nums.size();i++){
            if(mx<i){
                return false;
            }
            mx=max(mx,i+nums[i]);
        }
        return true;
    }
};