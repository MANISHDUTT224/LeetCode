class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
        int t=0;
        for(int i:nums){
            t|=i;
        }
        return t<<nums.size()-1;
    }
};