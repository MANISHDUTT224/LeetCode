class Solution {
public:
static constexpr int mod=1000000007;
    int lengthAfterTransformations(string s, int t) {
        vector<int>cnt(26,0);
        for(char c:s){
            cnt[c-'a']++;
        }
        for(int round=0;round<t;round++){
            vector<int>next(26,0);
            next[0]=cnt[25];
            next[1]=(cnt[25]+cnt[0])%mod;
            for(int i=2;i<26;i++){
                next[i]=cnt[i-1];
            }
            cnt=move(next);
        }
        int ans=0;
        for(int i=0;i<26;i++){
            ans=(ans+cnt[i])%mod;
        }
        return ans;
    }
};