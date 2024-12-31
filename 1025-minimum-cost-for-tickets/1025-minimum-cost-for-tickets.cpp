class Solution {
public:
    unordered_set<int>isTravelneeded;
    int solve(vector<int>&dp,vector<int>&days,vector<int>&costs,int curday){
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
        if(curday>days[days.size()-1]){
            return 0;
        }
        if(dp[curday]!=-1){
            return dp[curday];
        }
        if(isTravelneeded.find(curday)==isTravelneeded.end()){
            return solve(dp,days,costs,curday+1);
        }
        int oneday=costs[0]+solve(dp,days,costs,curday+1);
        int sevenday=costs[1]+solve(dp,days,costs,curday+7);
        int thirtyday=costs[2]+solve(dp,days,costs,curday+30);
        dp[curday]=min(oneday,min(sevenday,thirtyday));
        return dp[curday];
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int lastday=days[days.size()-1];
        vector<int>dp(lastday+1,-1);
        for(int day:days){
            isTravelneeded.insert(day);
        }
        return solve(dp,days,costs,1);
    }
};