class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
    if(grid[0][1]>1 && grid[1][0]>1){
        return -1;
    }
    int rows=grid.size();
    int cols=grid[0].size();
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> minheap;
    minheap.push({0,{0,0}});
    vector<vector<int>> seen(rows,vector<int>(cols,0));
    seen[0][0]=1;
    vector<vector<int>> directions={{0,1},{1,0},{-1,0},{0,-1}};
    while(!minheap.empty()){
        auto curr=minheap.top();
        int curtime=curr.first;
        int currow=curr.second.first;
        int curcol=curr.second.second;
        minheap.pop();
        if(currow==rows-1 && curcol==cols-1){
            return curtime;
        }
        for(auto move:directions){
            int nextrow=move[0]+currow;
            int nextcol=move[1]+curcol;
            if(nextrow>=0 && nextrow<rows && nextcol>=0 && nextcol<cols && !seen[nextrow][nextcol]){
                int waittime=((grid[nextrow][nextcol]-curtime)%2==0)?1:0;
                int nexttime=max(grid[nextrow][nextcol]+waittime,curtime+1);
                minheap.push({nexttime,{nextrow,nextcol}});
                seen[nextrow][nextcol]=1;
            }
        }
    }
    return -1;
    }
};