class Solution {
public:
    string shortestPalindrome(string s) {
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
        int n=s.size();
        int i=0;
        for(int j=n-1;j>=0;j--){
            while(j>=0 && s[i]==s[j]){
                i++;
                j--;
            }
        }
        if(i==n){
            return s;
        }
        string sub=s.substr(i),remrev=sub;
        reverse(remrev.begin(),remrev.end());
        return remrev+shortestPalindrome(s.substr(0,i))+sub;
    }
};