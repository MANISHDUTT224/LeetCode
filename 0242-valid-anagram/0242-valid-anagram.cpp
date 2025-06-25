class Solution {
public:
    bool isAnagram(string s, string t) {
        map<int,int>mp1;
        if(s.size()!=t.size()){
            return false;
        }
        for(auto it:s){
            mp1[it]++;
        }
        for(auto it:t){
            mp1[it]--;
        }
        for(auto it:mp1){
            if(it.second!=0){
                return false;
            }
        }
        return true;
    }
};