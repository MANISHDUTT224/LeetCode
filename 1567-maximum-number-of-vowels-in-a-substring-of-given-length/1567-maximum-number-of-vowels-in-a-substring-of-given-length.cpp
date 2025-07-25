class Solution {
public:
     bool isVow(char c){
        
            return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
        
     }
    int maxVowels(string s, int k) {
        int n=s.size();
        int vowcount=0;
        for(int i=0;i<k;i++){
            if(isVow(s[i])){
                vowcount++;
            }
        }
        int maxcount=vowcount;
        for(int i=1;i<=n-k;i++){
            if(isVow(s[i-1])){
                vowcount--;
            }
            if(isVow(s[i+(k-1)])){
                vowcount++;
            }
            maxcount=max(maxcount,vowcount);
        }

        return maxcount;
    }
};