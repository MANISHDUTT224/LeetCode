class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);

        sort(nums.begin(),nums.end());
        int moves=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<=nums[i-1]){
                moves+=nums[i-1]-nums[i]+1;
                nums[i]=nums[i-1]+1;
            }
        }
        return moves;
    }
};