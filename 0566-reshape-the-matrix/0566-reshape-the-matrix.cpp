class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int n=mat.size(),m=mat[0].size();
        vector<vector<int>>res(r,vector<int>(c,0));
        if(r*c!=m*n){
            return mat;
        }
        int row=0,col=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                res[row][col]=mat[i][j];
                col++;
                if(col==c){
                    row++;
                    if(row==r){
                        return res;
                    }
                    col=0;
                }
            }
        }
        return res;
       
    }
};