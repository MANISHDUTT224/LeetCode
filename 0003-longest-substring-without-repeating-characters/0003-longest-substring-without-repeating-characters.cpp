class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0,r=0;
        set<char>st;
        int curl,maxl=0;
        while(r<s.size()){
            if(st.find(s[r])==st.end()){
                st.insert(s[r]);
                curl=r-i;
                maxl=max(maxl,curl+1);
                r++;
            }
            else{
                st.erase(s[i]);
                i++;
            }
        }
        return maxl;
    }
};