class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>>mp;
        vector<vector<string>> res;
        for(string str:strs){
            string temp=str;
            sort(str.begin(),str.end());
            if(mp.find(str)==mp.end()){
                mp[str]={temp};
            }
            else{
                mp[str].push_back(temp);
            }
        }
        for(auto it:mp){
            vector<string>tempstringarray;
            for(auto i:it.second){
                tempstringarray.push_back(i);
            }
            res.push_back(tempstringarray);
        }
        return res;
    }
};