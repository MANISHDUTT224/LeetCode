class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
        int n=times.size();
        vector<int> order(n);
        for(int i=0;i<n;i++){
            order[i]=i;
        }
        sort(order.begin(),order.end(),[&times](int a,int b){
            return times[a][0]<times[b][0];
        });
        priority_queue<int,vector<int>,greater<int>> emptyseats;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>takenseats;
        for(int i=0;i<n;i++){
            emptyseats.push(i);
        }
        for(int i:order){
            int arrival=times[i][0],leave=times[i][1];
            while(!takenseats.empty() && takenseats.top().first<=arrival){
                emptyseats.push(takenseats.top().second);
                takenseats.pop();
            }
            int seat=emptyseats.top();
            emptyseats.pop();
            if(i==targetFriend){
                return seat;
            }
            takenseats.push({leave,seat});

        }
        return -1;
    }
};