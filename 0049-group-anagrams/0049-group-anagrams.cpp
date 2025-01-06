class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
        vector<vector<string>> result;
        map<string,vector<string>>mp;
        for(auto str:strs){
            string temp=str;
            sort(str.begin(),str.end());
            if(mp.find(str)==mp.end()){
                vector<string>temparr;
                temparr.push_back(temp);
                mp[str]=temparr;
            }
            else{
                mp[str].push_back(temp);
            }
        }
        for(auto it:mp){
            vector<string>t;
            for(auto i:it.second){
                t.push_back(i);
            }
            result.push_back(t);
        }
        return result;
    }
};