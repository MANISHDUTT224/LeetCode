class Solution {
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
        int n=edges1.size()+1;
        int m=edges2.size()+1;
        vector<vector<int>> adjlist1=findadjlist(edges1,n);
        vector<vector<int>> adjlist2=findadjlist(edges2,m);
        int diameter1=findiameter(adjlist1,0,-1).first;
        int diameter2=findiameter(adjlist2,0,-1).first;
        int combinediameter=ceil(diameter1/2.0)+ceil(diameter2/2.0)+1;
        return max({diameter1,diameter2,combinediameter});
    }
    vector<vector<int>> findadjlist(vector<vector<int>>&edges,int size){
        vector<vector<int>> adjlist(size);
        for(auto& it:edges){
            adjlist[it[0]].push_back(it[1]);
            adjlist[it[1]].push_back(it[0]);
        }
        return adjlist;
    }
    pair<int,int> findiameter(vector<vector<int>>&adjlist,int node,int parent){
        int diameter=0,maxdepth1=0,maxdepth2=0;
        for(int neighbor:adjlist[node]){
            if(neighbor==parent){
                continue;
            }
            auto [childiameter,depth]=findiameter(adjlist,neighbor,node);
            diameter=max(diameter,childiameter);
            depth++;
            if(depth>maxdepth1){
                maxdepth2=maxdepth1;
                maxdepth1=depth;
            
            }
            else if(depth>maxdepth2){
                maxdepth2=depth;
            }
            
        }
        diameter=max(diameter,maxdepth1+maxdepth2);
        return {diameter,maxdepth1};
    }
};