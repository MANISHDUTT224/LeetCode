class Solution {
public:
    int countPalindromicSubsequence(string s) {
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
        vector<int>first(26,-1);
        vector<int>last(26,-1);
        for(int i=0;i<s.size();i++){
            int curr=s[i]-'a';
            if(first[curr]==-1){
                first[curr]=i;
            }
            last[curr]=i;
        }
        int ans=0;
        for(int i=0;i<26;i++){
            if(first[i]==-1){
                continue;
            }
            unordered_set<int>between;
            for(int j=first[i]+1;j<last[i];j++){
                between.insert(s[j]);
            }
            ans+=between.size();
        }
        return ans;
    }
};