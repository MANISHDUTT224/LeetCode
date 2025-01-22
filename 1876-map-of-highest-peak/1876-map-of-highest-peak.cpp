class Solution {
public:
    bool isValid(int r,int c,int n,int m){
        return r>=0 && c>=0 && r<n && c<m;
    }
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n=isWater.size();
        int m=isWater[0].size();
        const int INF=n*m;
        vector<vector<int>>cellsHeight(n,vector<int>(m,INF));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isWater[i][j]){
                    cellsHeight[i][j]=0;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int minHeight=INF;
                if(isValid(i-1,j,n,m)){
                    minHeight=min(minHeight,cellsHeight[i-1][j]);
                }
                if(isValid(i,j-1,n,m)){
                    minHeight=min(minHeight,cellsHeight[i][j-1]);
                }
                cellsHeight[i][j]=min(cellsHeight[i][j],minHeight+1);
            }

        }
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                int minHeight=INF;
                if(isValid(i+1,j,n,m)){
                    minHeight=min(minHeight,cellsHeight[i+1][j]);
                }
                if(isValid(i,j+1,n,m)){
                    minHeight=min(minHeight,cellsHeight[i][j+1]);
                }
                cellsHeight[i][j]=min(minHeight+1,cellsHeight[i][j]);
            }
        }
        return cellsHeight;
    }

};