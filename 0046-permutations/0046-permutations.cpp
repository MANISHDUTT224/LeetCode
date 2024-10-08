class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
        vector<vector<int>> res;
        permuterec(nums,0,res);
        return res;
    }
    vector<vector<int>> permuterec(vector<int>&nums,int ci,vector<vector<int>>&res){
        if(ci==nums.size()-1){
            res.push_back(nums);
            return res;
        }
        for(int i=ci;i<nums.size();i++){
            swap(nums[ci],nums[i]);
            permuterec(nums,ci+1,res);
            swap(nums[ci],nums[i]);
        }
        return res;
    }
};