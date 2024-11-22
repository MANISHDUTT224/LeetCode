class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
        unordered_map<string,int>mp;
        for(auto it:matrix){
            bool flip=it[0]==1;
            string key;
            for(int num:it){
                key+=flip?('0'+(1-num)):'0'+num;
            }
            mp[key]++;
        }
        int maxcount=0;
        for(auto it:mp){
            maxcount=max(maxcount,it.second);
        }
        return maxcount;
    }
};