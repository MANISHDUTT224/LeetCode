class Solution {
public:
    string reverseWords(string s) {
        int n=s.size(),i=0;
        string result="";
       
        while(i<n){
           
            while(i<n && s[i]==' '){
                i++;
            }
            if(i==n){
                break;
            }
            int j=i+1;
            while(j<n && s[j]!=' '){
                j++;
            }
            string sub=s.substr(i,j-i);
            cout<<sub<<i<<j<<endl;
            if(result.size()==0){
                result=sub;
            }
            else{
                result=sub+" "+result;
            }
            
            i=j+1;
        }
        return result;
    }
};