class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long firstRowSum=accumulate(grid[0].begin(),grid[0].end(),0LL);
        long long secondRowSum=0;
        long long minimumsum=LONG_LONG_MAX;
        for(int i=0;i<grid[0].size();i++){
            firstRowSum-=grid[0][i];
            minimumsum=min(minimumsum,max(firstRowSum,secondRowSum));
            secondRowSum+=grid[1][i];
        }
        return minimumsum;
    }
};