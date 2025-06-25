class Solution {
public:
    string removeOuterParentheses(string s) {
        int count=0,i=0;
        int n=s.size();
        string result="";
        while(i<n){
            if(s[i]=='('){
                if(count>0){
                    result+=s[i];
                }
                count++;
            }
            else if(s[i]==')'){
                count--;
                if(count>0){
                    result+=s[i];
                }
            }
            i++;
        }
        return result;
    }
};