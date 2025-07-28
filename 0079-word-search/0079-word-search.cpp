class Solution {
public: 
    bool traverse(vector<vector<char>>&board,int i,int j,int n,int m,string word,int wordind){
        if(wordind==word.size()){
            return true;
        }

        if(i<0 || j<0 || i>=n || j>=m || board[i][j]!=word[wordind]){
                return false;
            }
        
            char back=board[i][j];
            board[i][j]='-';
           bool found= traverse(board,i-1,j,n,m,word,wordind+1)||
            traverse(board,i+1,j,n,m,word,wordind+1) ||
            traverse(board,i,j-1,n,m,word,wordind+1) ||
            traverse(board,i,j+1,n,m,word,wordind+1);
            board[i][j]=back;
        
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        bool found=false;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                
                   if(traverse(board,i,j,n,m,word,0)){
                    return true;
                   }
                }
            }
        }
       
        return false;
    }
};