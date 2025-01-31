class Solution {
public:
int dfs(vector<vector<int>>&grid,int islandid,int i,int j){
    int n=grid.size(),m=grid[0].size();
    if( i<0 || j<0 || i>=n || j>=m || grid[i][j]!=1){
        return 0;
    }
    grid[i][j]=islandid;
    return 1+dfs(grid,islandid,i+1,j)+dfs(grid,islandid,i-1,j)+dfs(grid,islandid,i,j+1)+dfs(grid,islandid,i,j-1);
}
    int largestIsland(vector<vector<int>>& grid) {
        unordered_map<int,int>islandsizes;
        int islandid=2;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    islandsizes[islandid]=dfs(grid,islandid,i,j);
                    islandid++;
                }
            }
        }
        if(islandsizes.empty()){
            return 1;
        }
        if(islandsizes.size()==1){
            --islandid;
            return (islandsizes[islandid]==grid.size()*grid[0].size())?islandsizes[islandid]:islandsizes[islandid]+1;
        }
        int maxislandsize=1;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==0){
                    int currentislandsize=1;
                    unordered_set<int>neighboringislands;
                    if(i+1<grid.size()&& grid[i+1][j]>1){
                        neighboringislands.insert(grid[i+1][j]);
                    }
                    if(i-1>=0&& grid[i-1][j]>1){
                        neighboringislands.insert(grid[i-1][j]);
                    }
                    if(j+1<grid[0].size()&& grid[i][j+1]>1){
                        neighboringislands.insert(grid[i][j+1]);
                    }
                    if(j-1>=0&& grid[i][j-1]>1){
                        neighboringislands.insert(grid[i][j-1]);
                    }
                    for(int id:neighboringislands){
                        currentislandsize+=islandsizes[id];
                    }
                    maxislandsize=max(maxislandsize,currentislandsize);
                }
            }
        }
        return maxislandsize;
    }
};