class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int len=spaces.size()+s.size();
        string res(len,' ');
        int it=0,skip=0;
        for(int i=0;i<s.size();i++){
            if(it<spaces.size() && i==spaces[it]){
                it++;
                skip++;
            }
            res[i+skip]=s[i];
        }
        return res;
    }
};