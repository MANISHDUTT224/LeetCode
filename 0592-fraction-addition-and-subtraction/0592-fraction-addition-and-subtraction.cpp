class Solution {
public:
    string fractionAddition(string expression) {
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
        int numer=0,den=1;
        int i=0,n=expression.size();
        while(i<n){
            int sign=1;
            if(expression[i]=='+'|| expression[i]=='-'){
                if(expression[i]=='-'){
                    sign=-1;
                }
                i++;
            }
            int num=0;
            while(i<n && isdigit(expression[i])){
                num=num*10+(expression[i]-'0');
                i++;
            }
            num*=sign;
            i++;
            int d=0;
            while(i<n && isdigit(expression[i])){
                d=d*10+(expression[i]-'0');
                i++;
            }
            numer=numer*d+num*den;
            den*=d;
            int gcdval=gcd(abs(numer),den);
            numer/=gcdval;
            den/=gcdval;
        }
        return to_string(numer)+"/"+to_string(den);

    }
};