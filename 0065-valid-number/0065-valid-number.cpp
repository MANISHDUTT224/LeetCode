class Solution {
public:
    bool isNumber(string s) {
        bool digit=false,sign=false,dot=false,exponent=false;
        if(s.size()==1 && (s[0]=='.' || s[0]=='+'||s[0]=='-'||s[0]=='e')){
            return false;
        }
        int ec=0;
        
        for(char c:s){
            
            if(c>='0' && c<='9'){
                digit=true;
                exponent=false;
                sign=false;
            }
            else if(c=='e' || c=='E'){
                if(exponent==true || digit==false){
                    return false;
                }
                else{
                    ec++;
                    exponent=true;
                    digit=false;
                    sign=false;
                    dot=false;
                }
            }
            else if(c=='+'||c=='-'){
                if(sign==true||dot==true||digit==true){
                    return false;
                }
                else{
                    sign=true;
                }
            }
            else if(c=='.'){
                if(exponent==true||dot==true || ec>0){
                    return false;
                }
                else{
                    dot=true;
                }
            }
            else{
                return false;
            }
            cout<<c<<endl;
           
        }
        if(exponent ||ec>1 ||(dot&&sign)){
            return false;
        }
        return true;
    }
};