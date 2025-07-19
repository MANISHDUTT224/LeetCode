class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        int i=rStart,j=cStart;
        int twice=2;
        int diri=0,dirj=1;
        int moves=1,next_moves=2;
        vector<vector<int>>res;
        while(res.size()<rows*cols){
            if(i>=0 && i<rows && j>=0 && j<cols){
                res.push_back({i,j});
            }
            i+=diri;
            j+=dirj;
            moves--;
            if(moves==0){
                int temp=diri;
                diri=dirj;
                dirj=-temp;
                twice--;
                if(twice==0){
                    twice=2;
                    moves=next_moves;
                    next_moves++;
                }
                else{
                    moves=next_moves-1;
                }
            }
        }
        return res;
    }
};