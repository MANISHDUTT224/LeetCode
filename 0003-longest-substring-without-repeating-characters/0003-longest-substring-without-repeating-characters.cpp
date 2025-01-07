class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0,r=0;
        int n=s.size();
        set<char>st;
        int curl,maxl=0;
        while(r<n){
            if(st.find(s[r])==st.end()){
                st.insert(s[r]);
                curl=r-l;
                maxl=max(maxl,curl+1);
                r++;
            }
            else{
                st.erase(s[l]);
                l++;
            }
        
        }
        return maxl;
    }
};