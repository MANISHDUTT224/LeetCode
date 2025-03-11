class Solution {
public:
    int numberOfSubstrings(string s) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int i=0; 
        int j=0;
        int ans=0;
        vector<int>v(3,0);
        for(int j=0; j<s.length(); j++){
            v[s[j]-'a']++;
            while(v[0]>0 && v[1]>0 && v[2]>0){
                v[s[i]-'a']--;
                i++;
            }
            ans+=i;

        }
            return ans;
        
        
    }
};