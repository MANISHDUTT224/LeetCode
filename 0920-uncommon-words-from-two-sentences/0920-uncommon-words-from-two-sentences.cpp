class Solution {
public:
    map<string,int> mp;
    void stringstreeam(string s){
        stringstream ss(s);
        string word;
        while(ss>>word){
            mp[word]++;
        }
    }
    vector<string> uncommonFromSentences(string s1, string s2) {
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
         stringstreeam(s1);
         stringstreeam(s2);
         vector<string> ans;
         for(auto x:mp){
            if(x.second==1){
                ans.push_back(x.first);
            }
         }
         return ans;
        }
    
};