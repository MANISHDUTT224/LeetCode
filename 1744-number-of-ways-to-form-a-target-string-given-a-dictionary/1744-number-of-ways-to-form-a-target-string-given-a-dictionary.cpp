class Solution {
public:
    int numWays(vector<string>& words, string target) {
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
        int wordlength=words[0].size();
        int targetlength=target.size();
        vector<vector<int>> charfreq(wordlength,vector<int>(26,0));
        for(auto it:words){
            for(int j=0;j<it.size();j++){
                charfreq[j][it[j]-'a']++;
            }
        }
        const int MOD=1000000007;
        vector<long>prevcount(targetlength+1,0);
        vector<long>curcount(targetlength+1,0);
        prevcount[0]=1;
        for(int curword=1;curword<=wordlength;++curword){
            curcount=prevcount;
            for(int curtarget=1;curtarget<=targetlength;++curtarget){
                int curpos=target[curtarget-1]-'a';
                curcount[curtarget]+=(charfreq[curword-1][curpos]*prevcount[curtarget-1])%MOD;
                curcount[curtarget]%=MOD;
            }
            prevcount=curcount;
        }
        return curcount[targetlength];

    }
};