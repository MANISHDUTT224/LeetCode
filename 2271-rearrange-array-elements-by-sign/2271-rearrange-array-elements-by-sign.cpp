class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int p=0,ne=1;
        vector<int>res(nums.size(),0);
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                res[p]=nums[i];
                p+=2;
            }
            else if(nums[i]<0){
                res[ne]=nums[i];
                ne+=2;
            }
        }
        return res;
    }
};