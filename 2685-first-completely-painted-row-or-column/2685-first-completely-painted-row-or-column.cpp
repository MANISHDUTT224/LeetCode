class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int numRows=mat.size(),numCols=mat[0].size();
        unordered_map<int,pair<int,int>>numToPos;
        vector<int>rowCount(numRows),colCount(numCols);
        for(int r=0;r<numRows;r++){
            for(int c=0;c<numCols;c++){
                int value=mat[r][c];
                numToPos[value]={r,c};
            }
        }
        for(int i=0;i<arr.size();i++){
            auto [r,c]=numToPos[arr[i]];
            rowCount[r]++;
            colCount[c]++;
            if(rowCount[r]==numCols || colCount[c]==numRows){
                return i;
            }
        }
        return -1;

    }
};