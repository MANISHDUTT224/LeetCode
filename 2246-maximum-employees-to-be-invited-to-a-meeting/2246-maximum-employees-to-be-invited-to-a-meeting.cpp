class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        int n=favorite.size();
        vector<int>depth(n,1);
        vector<int>inDegree(n,0);
        queue<int>q;
        for(int i=0;i<n;i++){
            inDegree[favorite[i]]++;
        }
        for(int i=0;i<n;i++){
            if(inDegree[i]==0){
                q.push(i);
            }
        }
        int twoCycleInvitations=0,longestCycle=0;
        while(!q.empty()){
            int currentnode=q.front();
            q.pop();
            int nextnode=favorite[currentnode];
            depth[nextnode]=max(depth[nextnode],depth[currentnode]+1);
            if(--inDegree[nextnode]==0){
                q.push(nextnode);
            }
        }
        for(int i=0;i<n;i++){
            if(inDegree[i]==0){
                continue;
            }
            int cycleLength=0;
            int current=i;
            while(inDegree[current]!=0){
                inDegree[current]=0;
                cycleLength++;
                current=favorite[current];
            }
            if(cycleLength==2){
                twoCycleInvitations+=depth[i]+depth[favorite[i]];
            }
            else{
                longestCycle=max(longestCycle,cycleLength);
            }

        }
        return max(longestCycle,twoCycleInvitations);
    }
};