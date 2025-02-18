class Solution {
public:
    int n,m;
    vector<pair<int,int>>dir={{-1,0},{0,-1},{1,0},{0,1}};
    void find(vector<vector<int>>&grid,vector<vector<int>>&dist){
       queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    dist[i][j]=0;
                    q.push({i,j});
                }
                else if(grid[i][j]==2){
                    dist[i][j]=-1;
                }
            }
        }

        int level=1;
        while(q.size()){
            int size=q.size();
            while(size--){
                auto temp=q.front();
                q.pop();
                int x=temp.first;
                int y=temp.second;
                for(auto it:dir){
                    int nx=x+it.first;
                    int ny=y+it.second;
                    if(nx>=0 && ny>=0 && nx<n && ny<m && dist[nx][ny]==INT_MAX && grid[nx][ny]==0){
                        dist[nx][ny]=level;
                        q.push({nx,ny});
                    }
                }
            }
            level++;
        }
    }
    bool check(int mid,vector<vector<int>>&dist){
        queue<vector<int>>q;
        q.push({0,0,mid});
           int vis[n][m];
        memset(vis,0,sizeof(vis));
        while(!q.empty()){
            auto x=q.front();
            q.pop();
            int row=x[0];
            int col=x[1];
            int cost=x[2];
            vis[row][col]=1;
            if(row==n-1 && col==m-1){
                return true;
            }
            for(auto it:dir){
                int nx=row+it.first;
                int ny=col+it.second;
                if(nx>=0 && ny>=0 && nx<n && ny<m && dist[nx][ny]!=-1 && !vis[nx][ny] &&((nx==n-1 && ny==m-1 && cost+1<=dist[nx][ny])||(cost+1<dist[nx][ny]))){
                    q.push({nx,ny,cost+1});
                
                }
               
            }
        }
        return false;
    }
    int maximumMinutes(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        find(grid,dist);
        int l=0,r=1e9;
        int mid;
        int ans=-1;
        while(l<=r){
            mid=(l+r)/2;
            if(check(mid,dist)){
                l=mid+1;
                ans=mid;
            }
            else{
                r=mid-1;
            }
        }
        return ans;
    }
};