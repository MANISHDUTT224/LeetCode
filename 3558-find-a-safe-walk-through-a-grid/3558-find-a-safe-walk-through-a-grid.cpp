class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n=grid.size();
        int m=grid[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>>maxheap;
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        if(grid[0][0]==1){
            maxheap.push({health-1,{0,0}});
        }
        else{
            maxheap.push({health,{0,0}});
        }
        vis[0][0]=true;
        int xdir[4]={-1,0,1,0};
        int ydir[4]={0,-1,0,1};
        while(!maxheap.empty()){
            auto val=maxheap.top().first;
            auto row=maxheap.top().second.first;
            auto col=maxheap.top().second.second;
            
             if(row==n-1 && col==m-1){
                    if(val>=1){
                        return true;
                    }
                }
                maxheap.pop();
            for(int i=0;i<4;i++){
                int x=row+xdir[i];
                int y=col+ydir[i];
               
                if(x>=0 && y>=0 && x<n && y<m && !vis[x][y]){
                    if(grid[x][y]==1){
                        maxheap.push({val-1,{x,y}});
                    }
                    else if(grid[x][y]==0){
                        maxheap.push({val,{x,y}});
                    }
                    vis[x][y]=1;
                }
            }
        }
        return false;
    }
};