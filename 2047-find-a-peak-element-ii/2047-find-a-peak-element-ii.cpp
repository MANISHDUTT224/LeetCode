class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        int i=0,j=m-1;
        //vector<int>ans;
        while(i<=j){
            int mid=i+(j-i)/2;
            int max_row=0;
            for(int i=0;i<n;i++){
               if(matrix[i][mid]>matrix[max_row][mid]){
                max_row=i;
               }
            }
            int left_val=-1,right_val=-1;
            if(mid-1>=0){
                left_val=matrix[max_row][mid-1];
            }
            if(mid+1<m){
                right_val=matrix[max_row][mid+1];
            }
            if(matrix[max_row][mid]>left_val && matrix[max_row][mid]>right_val){
                return {max_row,mid};
            }
            else if(matrix[max_row][mid]>right_val){
                j=mid-1;
            }
            else{
                i=mid+1;
            }
        }
        return {-1,-1};


    }
};