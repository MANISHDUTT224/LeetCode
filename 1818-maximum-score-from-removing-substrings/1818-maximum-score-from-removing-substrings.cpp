class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int ac=0,bc=0,lesser=min(x,y),res=0;
        for(int i=0;i<s.size();i++){
            if(s[i]>'b'){
                res+=min(ac,bc)*lesser;
                ac=0;
                bc=0;
            }
            else if(s[i]=='a'){
                if(x<y && bc>0){
                    bc--;
                    res+=y;
                }
                else{
                    ac++;
                }
            }
            else{
                if(x>y && ac>0){
                    ac--;
                    res+=x;
                }
                else{
                    bc++;
                }
            }
        }
        res+=min(ac,bc)*lesser;
        return res;
    }
};