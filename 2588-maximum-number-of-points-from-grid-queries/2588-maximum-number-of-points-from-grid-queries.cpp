class Solution {
public:
     int DIRECTIONS[4][2]={{-1,0},{1,0},{0,1},{0,-1}};
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int qc=queries.size();
        vector<int>result(qc);
        int n=grid.size();
        int m=grid[0].size();
        int totalcells=n*m;
        vector<int>threshold(totalcells+1);
        vector<vector<int>>minValtoReach(n,vector<int>(m,INT_MAX));
        minValtoReach[0][0]=grid[0][0];
        priority_queue<array<int,3>,vector<array<int,3>>,greater<array<int,3>>>minHeap;
        minHeap.push({grid[0][0],0,0});
        int visitedCells=0;
        while(!minHeap.empty()){
            array<int,3>current=minHeap.top();
            minHeap.pop();
            threshold[++visitedCells]=current[0];
            for(auto direction:DIRECTIONS){
                int newrow=current[1]+direction[0];
                int newcol=current[2]+direction[1];
                if(newrow>=0 && newcol>=0 && newrow<n && newcol<m && minValtoReach[newrow][newcol]==INT_MAX){
                    minValtoReach[newrow][newcol]=max(current[0],grid[newrow][newcol]);
                    minHeap.push({minValtoReach[newrow][newcol],newrow,newcol});
                }
            }
        }
        for(int i=0;i<qc;i++){
            int thres=queries[i];
            int left=0,right=totalcells;
            while(left<right){
                int mid=left+(right-left+1)/2;
                if(threshold[mid]<thres){
                    left=mid;
                }
                else{
                    right=mid-1;
                }
            }
            result[i]=left;
        }
        return result;
    }
};