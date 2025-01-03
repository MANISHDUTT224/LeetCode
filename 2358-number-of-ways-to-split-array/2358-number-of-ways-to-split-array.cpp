class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
         cin.tie(0);
         cout.tie(0);

         ios::sync_with_stdio(false);
        long long leftsum=0,rightsum=0;
        for(int num:nums){
            rightsum+=num;
        }
        int count=0;
        for(int i=0;i<nums.size()-1;i++){
            leftsum+=nums[i];
            rightsum-=nums[i];
            count+=leftsum>=rightsum;
        }
        return count;
    }
};