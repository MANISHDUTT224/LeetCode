class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int c=0;
       
        int top=0,left=0,bottom=n-1,right=n-1;
        vector<vector<int>>res(n,vector<int>(n,0));
        while(top<=bottom && left<=right){
            for(int i=left;i<=right;i++){
                res[top][i]=++c;
            }
            top++;
            for(int i=top;i<=bottom;i++){
                res[i][right]=++c; 
            }
            right--;
            if(top<=bottom){
                for(int i=right;i>=left;i--){
                    res[bottom][i]=++c;
                }
            }
            bottom--;
            if(left<=right){
                for(int i=bottom;i>=top;i--){
                    res[i][left]=++c;
                }
            }
            left++;
            
        }
        
       
        return res;

    }
};