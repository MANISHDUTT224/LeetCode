class Solution {
public:
    int findfishes(vector<vector<int>>&grid,int i,int j,vector<vector<bool>>&visited){
        if(i<0||j<0||i>=grid.size()||j>=grid[0].size()||grid[i][j]==0||visited[i][j]){
            return 0;
        }
        visited[i][j]=true;
        return grid[i][j]+findfishes(grid,i+1,j,visited)+findfishes(grid,i-1,j,visited)+findfishes(grid,i,j+1,visited)+findfishes(grid,i,j-1,visited);
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int rows=grid.size(),cols=grid[0].size();
        vector<vector<bool>>visited(rows,vector<bool>(cols,false));
        int maxFishes=0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                maxFishes=max(maxFishes,findfishes(grid,i,j,visited));
            }
        }
        return maxFishes;
    }
};