class Solution {
public:
    void dfs(int i,int j,vector<vector<char>> &grid,int n,int m,vector<int>rowdiff,vector<int>coldiff){
        grid[i][j]=0;
        for(int k=0;k<4;k++){
            int row=i+rowdiff[k];
            int col=j+coldiff[k];
            if(row>=0 && row<n && col>=0 && col<m && grid[row][col]=='1'){
                dfs(row,col,grid,n,m,rowdiff,coldiff);
            }

        }
        
    }
    int numIslands(vector<vector<char>>& grid) {
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
        int n=grid.size();
        int m=grid[0].size();
       int ans=0;
       vector<int>rowdiff={-1,1,0,0};

       vector<int> coldiff={0,0,1,-1};
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='1'){
                ans++;
                dfs(i,j,grid,n,m,coldiff,rowdiff);
            }
        }
       }
        return ans;
    }
};