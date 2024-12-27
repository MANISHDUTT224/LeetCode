class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
        int n=values.size();
        int maxleftscore=values[0],maxscore=0;

        for(int i=1;i<values.size();i++){
           int currentrightscore=values[i]-i;
           maxscore=max(maxscore,currentrightscore+maxleftscore);
           maxleftscore=max(maxleftscore,values[i]+i);
        }
        return maxscore;
    }
};