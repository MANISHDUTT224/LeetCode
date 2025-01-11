class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.size()<k){
            return false;
        }
        if(s.size()==k){
            return true;
            
        }
        int oddcount=0;
        for(char c:s){
            oddcount^=(1<<(c-'a'));
        }
        int setbits=__builtin_popcount(oddcount);
        return setbits<=k;
    }
};