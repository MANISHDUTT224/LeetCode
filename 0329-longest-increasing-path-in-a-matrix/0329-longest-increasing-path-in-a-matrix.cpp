class Solution {
public:
int n,m;
short path[200][200];
    int longestIncreasingPath(vector<vector<int>>& matrix) {
          n=matrix.size();
         m=matrix[0].size();
         cout<<n<<m<<endl;
        memset(path,0,sizeof(path));
        int max_path=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                max_path=max(max_path,dfs(i,j,matrix));
            }
        }
        return max_path;
    }
    int dfs(int i,int j,vector<vector<int>>&matrix){
        if(path[i][j]>0){
            return path[i][j];
        }
        if(path[i][j]==-1){
            return 0;
        }
        int max_next=0;
        path[i][j]=-1;
        if(i>0 && matrix[i-1][j]>matrix[i][j]){
            max_next=max(max_next,dfs(i-1,j,matrix));
        }
        if(j>0 && matrix[i][j-1]>matrix[i][j]){
            max_next=max(max_next,dfs(i,j-1,matrix));
        }
        if(i<n-1 && matrix[i+1][j]>matrix[i][j]){
            max_next=max(max_next,dfs(i+1,j,matrix));
        }

        if(j<m-1 && matrix[i][j+1]>matrix[i][j]){
            max_next=max(max_next,dfs(i,j+1,matrix));
        }
        return path[i][j]=1+max_next;
    }
};