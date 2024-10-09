class Solution {
public:
    int minAddToMakeValid(string s) {
        int cnt_open=0,cnt=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                cnt_open++;
            }
            else{
                if(cnt_open>0){
                    cnt_open--;
                }
                else{
                    cnt++;

                }

            }
        }
        return cnt+cnt_open;
    }
};