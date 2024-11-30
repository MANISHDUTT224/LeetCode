class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {

        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
        unordered_map<int,vector<int>>adj;
        unordered_map<int,int>deg;
        for(auto it:pairs){
            adj[it[0]].push_back(it[1]);
            deg[it[0]]++;
            deg[it[1]]--;
        }
        int startnode=pairs[0][0];
        for(auto it:deg){
            if(it.second==1){
                startnode=it.first;
                break;
            }
        }
        vector<int>path;
        stack<int>st;
        st.push(startnode);
        while(!st.empty()){
            auto &neighbors=adj[st.top()];
            if(neighbors.empty()){
                path.push_back(st.top());
                st.pop();
            }
            else{
                int nextnode=neighbors.back();
                st.push(nextnode);
                neighbors.pop_back();
            }
        }
        vector<vector<int>> arr;
        int pathsize=path.size();
        arr.reserve(pathsize-1);
        for(int i=pathsize-1;i>0;i--){
            arr.push_back({path[i],path[i-1]});
        }
        return arr;

    }
};