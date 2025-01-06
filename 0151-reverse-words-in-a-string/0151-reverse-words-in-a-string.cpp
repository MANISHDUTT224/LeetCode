class Solution {
public:
    string reverseWords(string s) {
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
        int i=0;
        string res;
        int n=s.size();
        while(i<n){
            while(i<n && s[i]==' '){
                i++;
            }
            if(i==n){
                break;
            }
            int j=i+1;
            while(j<n && s[j]!=' '){
                j++;
            }
            string w=s.substr(i,j-i);
            if(res.size()==0){
                res=w;
            }
            else{
                res=w+" "+res;
            }
            i=j+1;
        }
        return res;
    }
};