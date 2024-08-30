class Solution {
public:
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        vector<vector<pair<int,int>>> adj(n);
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
        for(auto e:edges){
            if(e[2]!=-1){
                adj[e[0]].push_back({e[1],e[2]});
                adj[e[1]].push_back({e[0],e[2]});
            }
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,source});
        vector<int> dis(n,1e9);
        dis[source]=0;
        while(!pq.empty()){
            int cur_dis=pq.top().first;
            int u=pq.top().second;
            pq.pop();
            if(u==destination){
                break;
            }
            for(auto nbr:adj[u]){
                int v=nbr.first;
                int wt=nbr.second;
                if(cur_dis+wt<dis[v]){
                    dis[v]=cur_dis+wt;
                    pq.push({dis[v],v});
                }
            }
        }
        if(dis[destination]<target){
            return {};
        }
        if(dis[destination]==target){
            for(auto &e:edges){
                if(e[2]==-1){
                    e[2]=1e9;
                }
            }
          
            return edges;
        }
        for(int i=0;i<edges.size();i++){
            auto &e=edges[i];
            if(e[2]==-1){
                e[2]=1;
                adj[e[1]].push_back({e[0],1});
                adj[e[0]].push_back({e[1],1});
            
            while(!pq.empty()){
                pq.pop();
            }
        pq.push({0,source});
        vector<int> dis(n,1e9);
        dis[source]=0;
        while(!pq.empty()){
            int cur_dis=pq.top().first;
            int u=pq.top().second;
            pq.pop();
            if(u==destination){
                break;
            }
            for(auto nbr:adj[u]){
                int v=nbr.first;
                int wt=nbr.second;
                if(cur_dis+wt<dis[v]){
                    dis[v]=cur_dis+wt;
                    pq.push({dis[v],v});
                }
            }
        }
            
                if(dis[destination]<=target){
                    e[2]+=target-dis[destination];
                    for(int j=i+1 ; j<edges.size() ; j++){
                        if(edges[j][2]==-1){
                            edges[j][2]=1e9;
                        }
                    }
                    return edges;
                }
            }
        }
            return {};
        }
};