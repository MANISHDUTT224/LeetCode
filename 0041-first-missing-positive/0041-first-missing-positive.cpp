class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int cnt=1;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                if(nums[i]==cnt){
                    cnt++;
                }
                else if(nums[i]<cnt){
                    continue;
                }
                else{
                    break;
                }
            }
        }
        return cnt;
    }
};