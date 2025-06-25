class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        set<int>st;
        int curl=0,maxlen=0;
        int l=0,r=0;
        while(r<n){
            if(st.find(s[r])==st.end()){
                st.insert(s[r]);
                curl=r-l;
                maxlen=max(maxlen,curl+1);
                r++;
            }
            else{
                st.erase(s[l]);
                l++;
            }
        }
        return maxlen;
    }
};