class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>graph(n);
        for(auto it:edges){
            int u=it[0],v=it[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        vector<bool>visited(n,false);
        int completecomponents=0;
        for(int edge=0;edge<n;edge++){
            if(!visited[edge]){
                queue<int>q;
                vector<int>component;
                q.push(edge);
                visited[edge]=true;
                while(!q.empty()){
                    int current=q.front();
                    q.pop();
                    component.push_back(current);
                    for(int neighbor:graph[current]){
                        if(!visited[neighbor]){
                            q.push(neighbor);
                            visited[neighbor]=true;
                        }
                    }
                }
                bool isComplete=true;
                for(int node:component){
                    if(graph[node].size()!=component.size()-1){
                        isComplete=false;
                        break;
                    }
                }
                if(isComplete){
                    completecomponents++;
                }
            }
        }
        return completecomponents;
    }
};