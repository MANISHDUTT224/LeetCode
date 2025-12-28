class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m=grid[0].size(),n=grid.size();
        int i=0,j=m-1;
        int count=0;
        while(i<n && j>=0){
            if(grid[i][j]>=0){
                i++;
            }
            else{
                count+=(n-i);
                j--;
            }
        }
        return count;
    }
};