class Solution {
public:
    int numSteps(string s) {
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
        int n=s.size();
        int ans=n-1,carry=0;
        for(int i=n-1;i>0;i--){
            if(s[i]-'0' +carry==1){
                ans++;
                carry=1;
            }
        }
        return ans+carry;
    }
};