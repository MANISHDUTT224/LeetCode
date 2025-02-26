class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        const int n=graph.size();
        queue<tuple<int,int,int>>q;
        set<pair<int,int>>vis;
        for(int i=0;i<n;i++){
            int cm=1<<i;
            q.emplace(cm,i,0);
            vis.insert({cm,i});
        }
        int allnodes=(1<<n)-1;
        while(!q.empty()){
            auto[mask,node,steps]=q.front();
            q.pop();
            if(mask==allnodes){
                return steps;
            }
            for(int neighbor:graph[node]){
                int cm=mask|1<<neighbor;
                if(vis.count({cm,neighbor})==0){
                    vis.insert({cm,neighbor});
                    q.emplace(cm,neighbor,steps+1);
                }
            }
        }
        return -1;
    }
};