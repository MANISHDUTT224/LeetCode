class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        long ans=0;
        int n=s.size();
        while(i<n && s[i]==' '){
            i++;
        }
        int sign=1;
        if(s[i]=='-'){
            sign=-1;
            i++;
        }
        else if(s[i]=='+'){
            sign=1;
            i++;
        }
        while(i<n){
            if(s[i]>='0' && s[i]<='9'){
                ans=ans*10+s[i]-'0';
                if(ans>INT_MAX ){
                    return (sign==-1)?INT_MIN:INT_MAX;
                }
            }
            else{
                return ans*sign;
            }
            i++;
        }
        return ans*sign;
    }
};