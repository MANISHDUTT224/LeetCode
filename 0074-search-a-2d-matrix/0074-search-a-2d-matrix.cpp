class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r=0,n=matrix.size(),c=matrix[0].size()-1,m=c+1;
        while(r<n && c>=0){
            if(matrix[r][c]==target){
                return true;
            }
            else if(matrix[r][c]<target){
                r++;
            }
            else{
                c--;
            }
        }
        return false;
    }
};