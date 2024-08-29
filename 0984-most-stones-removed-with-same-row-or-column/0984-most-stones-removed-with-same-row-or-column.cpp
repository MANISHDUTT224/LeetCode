class Solution {
public:
    void dfs(int &n,int &idx,vector<vector<int>> &stones,vector<bool>&visited){
        
        visited[idx]=true;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                if(stones[i][0]==stones[idx][0]){
                    dfs(n,i,stones,visited);
                }
                if(stones[idx][1]==stones[i][1]){
                    dfs(n,i,stones,visited);
                }
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
        int n=stones.size();
        int group=0;
        vector<bool>visited(n);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(n,i,stones,visited);
                group+=1;
            }
        }
        return n-group;
    }
};