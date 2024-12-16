class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
        set<int>points;
        for(int i=0;i<nums.size();i++){
            for(int j=nums[i][0];j<=nums[i][1];j++){
                points.insert(j);
            }
        }
        return points.size();
    }
};