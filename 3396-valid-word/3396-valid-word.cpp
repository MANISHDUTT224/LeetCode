class Solution {
public:
    bool isValid(string word) {
        if(word.size()<3){
            return false;
        }
        int vc=0,cc=0;
        for(char c:word){
            if(c=='a' || c=='A'|| c=='E' || c=='e' || c=='I'|| c=='i'|| c=='o'|| c=='O'|| c=='u'|| c=='U'){
                vc++;
            }
            else if((c>=97 && c<=122)||(c>=65 && c<=90)){ 
                cc++;
            }
            else if(isdigit(c)){
                continue;
            }
            else{
                return false;
            }
            
        }
        if(vc>=1 && cc>=1){
                return true;
            }
        return false;
    }
};