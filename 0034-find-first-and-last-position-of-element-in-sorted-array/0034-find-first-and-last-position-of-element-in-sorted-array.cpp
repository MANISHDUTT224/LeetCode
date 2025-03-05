class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first=-1,last=-1;
        int c=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target){
                if(c==0){
                    first=i;
                    last=first;
                    c=1;
                }
                else{
                    last=i;
                }
            }
        }
        return {first,last};
    }
};