class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char>st;
        int maxlen=INT_MIN;
        int l=0,r=0;
        int n=s.size();
        while(r<n){
           if(st.find(s[l])!=st.end()){
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