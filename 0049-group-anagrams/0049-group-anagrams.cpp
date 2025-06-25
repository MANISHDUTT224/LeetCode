class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>result;
        map<string,vector<string>>mp;
        for(auto it:strs){
            string temp=it;
            sort(temp.begin(),temp.end());
            mp[temp].push_back(it);
        }
        for(auto it:mp){
            result.push_back(it.second);
        }
        return result;
    }
};