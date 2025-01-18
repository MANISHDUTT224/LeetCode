class Solution {
public:
    const vector<vector<int>> dirs={{0,1},{0,-1},{1,0},{-1,0}};
    int minCost(vector<vector<int>>& grid) {
        int numRows=grid.size(),numCols=grid[0].size();
        int cost=0;
        queue<pair<int,int>> queue;
        vector<vector<int>>mincost(numRows,vector<int>(numCols,INT_MAX));
        dfs(0,0,mincost,cost,grid,queue);
        while(!queue.empty()){
            cost++;
            int levelsize=queue.size();
            while((levelsize--)>0){
                 auto[row,col]=queue.front();
                 queue.pop();
                for(int dir=0;dir<4;dir++){
                    dfs(row+dirs[dir][0],col+dirs[dir][1],mincost,cost,grid,queue);
                }
            }
        }
        return mincost[numRows-1][numCols-1];
    }
    void dfs(int row,int col,vector<vector<int>>&mincost,int cost,vector<vector<int>>&grid,queue<pair<int,int>>&queue){
        if(!isUnvisited(row,col,mincost)){
            return;
        }
        mincost[row][col]=cost;
        queue.push({row,col});
        int nextdir=grid[row][col]-1;
        dfs(row+dirs[nextdir][0],col+dirs[nextdir][1],mincost,cost,grid,queue);
    }
    bool isUnvisited(int row,int col,vector<vector<int>>&mincost){
        return row>=0 && col>=0 && row<mincost.size() && col<mincost[0].size() && mincost[row][col]==INT_MAX;
    }
};