class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
        int l=0,r=0,n=s.size();
        set<char>st;
        int maxl=0;
        while(r<n){
            if(st.find(s[r])==st.end()){
                st.insert(s[r]);
                int curl=r-l+1;
                maxl=max(maxl,curl);
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