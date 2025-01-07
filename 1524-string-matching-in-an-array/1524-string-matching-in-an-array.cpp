class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
        set<string>result;
        for(int i=0;i<words.size();i++){
            for(int j=0;j<words.size();j++){
                if(i!=j && words[j].find(words[i])!=string::npos){
                    result.insert(words[i]);
                }
            }
        }
        vector<string>v(result.begin(),result.end());
        return v;
    }
};