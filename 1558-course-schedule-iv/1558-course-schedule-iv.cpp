class Solution {
public:
    void preprocess(int numCourses,vector<vector<int>>&prerequisites,unordered_map<int,vector<int>>adjlist,vector<vector<bool>>&isPrerequisite){
        
        for(int i=0;i<numCourses;i++){
            queue<int>q;
            q.push(i);
            while(!q.empty()){
                int node=q.front();
                q.pop();
                for(auto it:adjlist[node]){
                    if(!isPrerequisite[i][it]){
                        isPrerequisite[i][it]=true;
                        q.push(it);
                    }
                }
            }
        }
    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        unordered_map<int,vector<int>>adjlist;
        for(auto edge:prerequisites){
            adjlist[edge[0]].push_back(edge[1]);
        }
        vector<vector<bool>>isPrerequisite(numCourses,vector<bool>(numCourses,false));
        preprocess(numCourses,prerequisites,adjlist,isPrerequisite);
        vector<bool>answer;
        for(auto q:queries){
            answer.push_back(isPrerequisite[q[0]][q[1]]);
        }
        return answer;
    }
};