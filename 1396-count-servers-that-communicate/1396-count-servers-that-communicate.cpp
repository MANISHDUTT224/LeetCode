class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        vector<int>rowcount(size(grid[0]),0),colcount(size(grid),0);
        for(int i=0;i<size(grid);i++){
            for(int j=0;j<size(grid[0]);j++){
                if(grid[i][j]){
                    rowcount[j]++;
                    colcount[i]++;
                }
            }
        }
        int communicableservercount=0;
        for(int i=0;i<size(grid);i++){
            for(int j=0;j<size(grid[0]);j++){
                if(grid[i][j]){
                    communicableservercount+=rowcount[j]>1||colcount[i]>1;
                }
            }
        }
        return communicableservercount;
    }
};