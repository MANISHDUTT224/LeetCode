class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int rec=nums[0],ans=1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]-rec>k){
                ans++;
                rec=nums[i];
            }
        }
        return ans;
    }
};