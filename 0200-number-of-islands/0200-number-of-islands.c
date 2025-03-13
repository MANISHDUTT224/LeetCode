void dfs(int ,int ,char **,int ,int*);
void dfs(int i,int j,char **grid,int gridSize,int *gridColSize){
    if(i>=0 && j>=0 && i<gridSize && j<gridColSize[i]){
        if(grid[i][j]=='0'){
            return;
        }
        grid[i][j]='0';
        dfs(i+1,j,grid,gridSize,gridColSize);
        dfs(i-1,j,grid,gridSize,gridColSize);
        dfs(i,j+1,grid,gridSize,gridColSize);
        dfs(i,j-1,grid,gridSize,gridColSize);
        return;
    }
}
int numIslands(char** grid, int gridSize, int* gridColSize) {
    int islands=0;
    for(int i=0;i<gridSize;i++){
        for(int j=0;j<gridColSize[i];j++){
            if(grid[i][j]=='1'){
                islands++;
                dfs(i,j,grid,gridSize,gridColSize);
            }
        }
    }
    return islands;
}