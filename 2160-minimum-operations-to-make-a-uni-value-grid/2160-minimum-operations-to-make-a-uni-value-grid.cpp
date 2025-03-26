class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int>numsArray;
        int n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]%x!=grid[0][0]%x){
                   return -1;
                }
                numsArray.push_back(grid[i][j]);
            }
        }
        sort(numsArray.begin(),numsArray.end());
        int N=numsArray.size();
        int i=0,j=N-1;
        int result=0;
        while(i<j){
            if(i<N-j-1){
                int minoperations=(i+1)*(numsArray[i+1]-numsArray[i])/x;
                result+=minoperations;
                i++;
            }
            else{
                int minopr=(N-j)*(numsArray[j]-numsArray[j-1])/x;
                result+=minopr;
                j--;
            }

        }
        return result;
    }
};