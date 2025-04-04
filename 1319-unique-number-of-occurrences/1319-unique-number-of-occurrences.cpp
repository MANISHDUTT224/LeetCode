class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int>mp;
        for(int i:arr){
            mp[i]++;
        }
        set<int>st;
        for(auto it:mp){
            if(st.find(it.second)==st.end()){
                st.insert(it.second);
            }
            else{
                return false;
            }
        }
        return true;
    }
};