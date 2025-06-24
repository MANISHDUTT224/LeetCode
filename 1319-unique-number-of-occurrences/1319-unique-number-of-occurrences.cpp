class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int>mp;
        set<int>st;
        for(int num:arr)
        {
            mp[num]++;
            
        }
        for(auto it:mp){
          if(it.second>0){
            st.insert(it.second);
          }
        }
        
        set<int>st2(arr.begin(),arr.end());
        return st.size()==st2.size();
    }
};