class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
        int result=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(magisquare(i,j,grid)){
                    result++;
                }
            }
        }
        return result;
    }

    bool magisquare(int i,int j,vector<vector<int>> &grid){
        if(i+2<grid.size() && j+2<grid[i].size()){
            int c1=grid[i][j]+grid[i][j+1]+grid[i][j+2];
            int c2=grid[i+1][j]+grid[i+1][j+1]+grid[i+1][j+2];
            int c3=grid[i+2][j]+grid[i+2][j+1]+grid[i+2][j+2];
            int r1=grid[i][j]+grid[i+1][j]+grid[i+2][j];
            int r2=grid[i][j+1]+grid[i+1][j+1]+grid[i+2][j+1];
            int r3=grid[i][j+2]+grid[i+1][j+2]+grid[i+2][j+2];
            int diag1=grid[i][j]+grid[i+1][j+1]+grid[i+2][j+2];
            int diag2=grid[i][j+2]+grid[i+1][j+1]+grid[i+2][j];
            if(c1==c2 && c1==c3 && c1==r1 && c1==r2 && c1==r3 && c1==diag1 && c1==diag2){
                set<int>st({1,2,3,4,5,6,7,8,9});
                for(int i1=0;i1<3;i1++){
                    for(int j1=0;j1<3;j1++){
                        st.erase(grid[i+i1][j+j1]);
                    }
                }
                return st.empty();

            }
            
        }
        return false;
    }
};