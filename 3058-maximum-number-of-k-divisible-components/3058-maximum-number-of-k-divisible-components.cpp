class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
    // cin.tie(0);
    // cout.tie(0);
    // ios::sync_with_stdio(false);
        if(n<2){
            return 1;
        }
        int componentcount=0;
        vector<vector<int>> graph(n);
        vector<int>indegree(n,0);
        for(auto it:edges){
            int node1=it[0],node2=it[1];
            graph[node1].push_back(node2);
            graph[node2].push_back(node1);
            indegree[node1]++;
            indegree[node2]++;
        }

        queue<int>queue;
        for(int node=0;node<n;node++){
            if(indegree[node]==1){
                queue.push(node);
            }
        }
        vector<long long >longvalues(values.begin(),values.end());
        while(!queue.empty()){
            int currentnode=queue.front();
            queue.pop();
            long long addvalue=0;
            indegree[currentnode]--;
            if(longvalues[currentnode]%k==0){
                componentcount++;
            }
            else{
                addvalue=longvalues[currentnode];
            }
            for(int neighbornode:graph[currentnode]){
                if(indegree[neighbornode]==0){
                    continue;
                }
                indegree[neighbornode]--;
                longvalues[neighbornode]+=addvalue;
                if(indegree[neighbornode]==1){
                    queue.push(neighbornode);
                }
            }
        }
        return componentcount;
    }
};