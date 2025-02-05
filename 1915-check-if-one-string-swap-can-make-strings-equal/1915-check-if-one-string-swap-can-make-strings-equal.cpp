class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1==s2){
            return true;
        }
        if(s1.size()!=s2.size()){
            return false;
        }
        int mismatchcount=0;
        int charcount1=0,charcount2=0;
        for(int i=0;i<s1.size();i++){
            
            
            if(s1[i]!=s2[i]){
                mismatchcount++;
                
            
            if(mismatchcount>2){
                return false;
            }
          else if(mismatchcount==1){
            charcount1=i;
          }
          else {
            charcount2=i;
          }
            }
        }
        cout<<charcount1<<" "<<charcount2;
        return s1[charcount1]==s2[charcount2] && s2[charcount1]==s1[charcount2];
    }
};