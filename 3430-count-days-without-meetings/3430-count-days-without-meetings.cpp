class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int freedays=0,latestend=0;
        sort(meetings.begin(),meetings.end());
        for(auto &meeting:meetings){
            int start=meeting[0],end=meeting[1];
            if(start>latestend+1){
                freedays+=start-latestend-1;
            }
            latestend=max(latestend,end);
        }
        freedays+=days-latestend;
        return freedays;
    }
};