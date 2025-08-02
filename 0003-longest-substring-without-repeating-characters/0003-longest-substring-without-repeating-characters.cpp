class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<int>st;
        int maxlen=INT_MIN;
        int l=0,r=0;
        int n=s.size();
        if(s.size()==0){
            return 0;
        }
        while(r<n){
           if(st.find(s[r])!=st.end()){
            st.erase(s[l]);
            
            l++;
           }
           else{
           st.insert(s[r]);
           maxlen=max(maxlen,r-l+1);
           r++;
           }
        }
        return maxlen;
    }
};