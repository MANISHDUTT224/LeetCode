class Solution {
public:
    bool isValid(string s) {
        char st[1000000];
     
        int top=-1;
        for(int i=0;s[i]!='\0';i++){
            if(s[i]=='('||s[i]=='['||s[i]=='{'){
                st[++top]=s[i];
            }
            else{
                if((top==-1)||(st[top]!='('&& s[i]==')')||(st[top]!='[' && s[i]==']')||(st[top]!='{' && s[i]=='}')){
                    return false;
                }
                top--;
            }
        }
        return top==-1;
    }
};