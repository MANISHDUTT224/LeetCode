class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        map<char,int>mp;
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
        for(auto it:allowed){
            mp[it]++;
        }
        int count=0;
        for(string it:words){
            int f=0;
            for(auto s:it){
                if(mp.find(s)==mp.end()){
                    f=1;
                    break;
                }
            }
            if(f==0){
                count++;
                
            }

        }
        return count;
    }
};