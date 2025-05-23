class Solution {
public:
    int maximumLength(string s) {
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
        int n=s.size(),l=1,r=n;
        if(!helper(s,n,l)){
            return -1;
        }
        while(l+1<r){
            int mid=(l+r)/2;
            if(helper(s,n,mid)){
                l=mid;
            }
            else{
                r=mid;
            }
        }
        return l;
    }
    bool helper(const string&s,int n,int x){
        vector<int>cnt(26,0);
        int p=0;
        for(int i=0;i<n;i++){
            while(s[i]!=s[p]){
                p++;
            }
            if(i-p+1>=x){
                cnt[s[i]-'a']++;
            }
            if(cnt[s[i]-'a']>2){
                return true;
            }
        }
        return false;
    }
};