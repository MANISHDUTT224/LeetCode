class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
        int n=s.size(),l=0,r=0;
        set<char>st;
        int maxlen=0;
        while(r<n){
            if(st.find(s[r])==st.end()){
                st.insert(s[r]);
                int cur=r-l+1;
                maxlen=max(maxlen,cur);
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