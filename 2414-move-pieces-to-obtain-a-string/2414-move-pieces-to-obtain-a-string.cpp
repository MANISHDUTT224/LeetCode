class Solution {
public:
    bool canChange(string s, string t) {
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
        int n=s.size();
        int i=0,j=0;
        while(i<n || j<n){
            while(i<n && s[i]=='_'){
                i++;
            }
            while(j<n && t[j]=='_'){
                j++;
            }
            char c=s[i];
            if(c!=t[j] ||(c=='L' && i<j)||(c=='R' && i>j)){
                return 0;
            }
            i++;
            j++;
        }
        return 1;
    }
};