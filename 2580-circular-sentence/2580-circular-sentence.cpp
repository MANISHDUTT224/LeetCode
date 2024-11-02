class Solution {
public:
    bool isCircularSentence(string sentence) {
        int n=sentence.size();
        if(sentence[0]!=sentence[n-1]){
            return false;
        }
        char lastalpha='$';
        for(int i=0;i<n;i++){
            if(sentence[i]==' '){
                lastalpha=sentence[i-1];
            }
            if(lastalpha!='$' && sentence[i-1]==' '){
                if(lastalpha==sentence[i]){
                    lastalpha='$';
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};