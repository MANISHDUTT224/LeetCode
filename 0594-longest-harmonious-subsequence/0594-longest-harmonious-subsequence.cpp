class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int j=0,maxlength=0,n=nums.size();
        for(int i=0;i<n;i++){
            while(nums[i]-nums[j]>1){
                ++j;
            }
            if(nums[i]-nums[j]==1){
                maxlength=max(maxlength,i-j+1);
            }
        }
        return maxlength;
    }
};