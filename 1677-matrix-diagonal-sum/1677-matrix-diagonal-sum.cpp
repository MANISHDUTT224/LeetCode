class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int leftdiagonal=0,rightdiagonal=0;
        for(int i=0;i<n;i++){
            leftdiagonal+=mat[i][i];
            rightdiagonal+=mat[i][n-i-1];
        }
        int res=leftdiagonal+rightdiagonal;
        if(n%2){
            res-=mat[n/2][n/2];
        }
        return res;
        
    }
};