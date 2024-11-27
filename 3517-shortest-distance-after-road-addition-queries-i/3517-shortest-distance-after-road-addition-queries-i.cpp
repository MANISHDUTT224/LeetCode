class Solution {
private:
    void updatedistances(vector<vector<int>> &graph,int source,vector<int> &dist){
        int newdist=dist[source]+1;
        for(int neighbor:graph[source]){
            if(dist[neighbor]<=newdist){
                continue;
            }
            dist[neighbor]=newdist;
            updatedistances(graph,neighbor,dist);
        }
    }
public:

    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
        vector<int>distances(n);
        for(int i=0;i<n;i++){
            distances[i]=n-1-i;
        }
        vector<vector<int>>graph(n);
        for(int i=0;i+1<n;i++){
            graph[i+1].push_back(i);
        }
        vector<int>ans(queries.size());
        int queryidx=0;
        for(const auto &query:queries){
            int source=query[0];
            int destination=query[1];
            graph[destination].push_back(source);
            distances[source]=min(distances[source],distances[destination]+1);
            updatedistances(graph,source,distances);
            ans[queryidx++]=distances[0];
        }
        return ans;
    }
};