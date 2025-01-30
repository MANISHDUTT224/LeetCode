class Solution {
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adjlist(n);
        vector<int>parent(n,-1);
        vector<int>depth(n,0);
        for(auto edge:edges){
            adjlist[edge[0]-1].push_back(edge[1]-1);
            adjlist[edge[1]-1].push_back(edge[0]-1);
            Union(edge[0]-1,edge[1]-1,parent,depth);
        }
        unordered_map<int,int>numOfGroupsForComponent;
        for(int node=0;node<n;node++){
            int numberOfGroups=getNumberOfGroups(adjlist,node,n);
            if(numberOfGroups==-1){
                return -1;
            }
            int rootnode=find(node,parent);
            numOfGroupsForComponent[rootnode]=max(numOfGroupsForComponent[rootnode],numberOfGroups);
        }
        int totalNumberOfGroups=0;
        for(auto[rootnode,numberOfGroups]:numOfGroupsForComponent){
            totalNumberOfGroups+=numberOfGroups;
        }
        return totalNumberOfGroups;
    }
private:
int find(int node,vector<int>&parent){
    while(parent[node]!=-1){
        node=parent[node];
    }
    return node;
}
void Union(int node1,int node2,vector<int>&parent,vector<int>&depth){
     node1=find(node1,parent);
     node2=find(node2,parent);
    if(node1==node2)return;
    if(depth[node1]<depth[node2]){
        swap(node1,node2);
        
        }
        parent[node2]=node1;
    if(depth[node1]==depth[node2]){
        depth[node1]++;
    }
}
int getNumberOfGroups(vector<vector<int>>&adjlist,int srcNode,int n){
queue<int>nodequeue;
vector<int>layerseen(n,-1);
nodequeue.push(srcNode);
layerseen[srcNode]=0;
int deepestLayer=0;
while(!nodequeue.empty()){
    int numOfNodesInLayer=nodequeue.size();
    for(int i=0;i<numOfNodesInLayer;i++){
    int currentnode=nodequeue.front();
    nodequeue.pop();
    for(int neighbor:adjlist[currentnode]){
        if(layerseen[neighbor]==-1){
            layerseen[neighbor]=deepestLayer+1;
            nodequeue.push(neighbor);
        }
        else{
            if(layerseen[neighbor]==deepestLayer){
                return -1;
            }
        }
    }
}
deepestLayer++;
}
return deepestLayer;
}
};
