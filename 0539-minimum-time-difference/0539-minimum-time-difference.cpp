class Solution {
public:
    
    int findMinDifference(vector<string>& timePoints) {
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
        vector<int> minutes(timePoints.size());
        for(int i=0;i<timePoints.size();i++){
            int h=stoi(timePoints[i].substr(0,2));
            int m=stoi(timePoints[i].substr(3));
            minutes[i]=h*60+m;
        }
        sort(minutes.begin(),minutes.end());
        int mindiff=INT_MAX;
        for(int i=0;i<minutes.size()-1;i++){
            mindiff=min(mindiff,minutes[i+1]-minutes[i]);
        }
        mindiff=min(mindiff,24*60-minutes.back()+minutes.front());
        return mindiff;
    }
};