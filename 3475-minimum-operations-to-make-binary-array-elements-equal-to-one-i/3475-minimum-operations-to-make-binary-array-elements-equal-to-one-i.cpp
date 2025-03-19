class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size(),count=0;
        for(int i=2;i<n;i++){
            if(nums[i-2]==0){
                count++;
                nums[i-2]^=1;
                nums[i-1]^=1;
                nums[i]^=1;
            }
        }
        int cnt=accumulate(nums.begin(),nums.end(),0);
        if(cnt==nums.size()){
            return count;
        }
        return -1;

    }
};