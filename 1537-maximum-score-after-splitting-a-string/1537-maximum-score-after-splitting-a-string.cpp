class Solution {
public:
    int maxScore(string s) {
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
        int ones=0,zeros=0,best=INT_MIN;
        for(int i=0;i<s.size()-1;i++){
            char c=s[i];
            if(c=='0'){
                zeros++;
            }
            else{
                ones++;
            }
            best=max(best,zeros-ones);
        }
        if(s[s.size()-1]=='1'){
            ones++;
        }
        return best+ones;
    }
};