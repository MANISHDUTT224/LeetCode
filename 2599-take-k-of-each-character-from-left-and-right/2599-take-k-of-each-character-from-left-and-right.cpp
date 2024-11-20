class Solution {
public:
    int takeCharacters(string s, int k) {
        vector<int> count(3,0);
        int maxlen=INT_MIN;
        for(char c:s){
            count[c-'a']++;
        }
        if(count[0]<k || count[1]<k|| count[2]<k){
            return -1;
        }
        int l=0;
        vector<int> cur(3,0);
        for(int r=0;r<s.size();r++){
            cur[s[r]-'a']++;
            while(l<=r &&(cur[0]>count[0]-k||cur[1]>count[1]-k||cur[2]>count[2]-k)){
                cur[s[l]-'a']--;
                l++;
            }
            maxlen=max(maxlen,r-l+1);
        }
        int n=s.size();
        return n-maxlen;
    }

};