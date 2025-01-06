class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
        vector<vector<string>>res;
        map<string,vector<string>>mp;
       
        for(auto str:strs){
            string temp=str;
            vector<string>tempstringarr;
            tempstringarr.push_back(temp);
            sort(str.begin(),str.end());
            if(mp.find(str)==mp.end()){
                mp[str]=tempstringarr;
            }
            else{
                mp[str].push_back(temp);
            }
        }
        for(auto it:mp){
            vector<string>temp;
            for(auto i:it.second){
                temp.push_back(i);
            }
            res.push_back(temp);
        }
        return res;
    }
};