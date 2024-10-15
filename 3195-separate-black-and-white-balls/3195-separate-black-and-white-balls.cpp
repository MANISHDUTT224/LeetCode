class Solution {
public:
    long long minimumSteps(string s) {
        cin.tie(0);
        cout.tie(0);

        ios::sync_with_stdio(false);
    long long ans=0,c=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='1'){
            c++;
        }
        else{
            ans+=c;
        }
    }
    return ans;
    }
};