class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n=s.size(),m=t.size();
        int first=0,second=0;
        while(second<m){
            if(s[first]==t[second]){
                first++;
                second++;
            }
            else{
                second++;
            }
        }
        return first==n;
    }
};