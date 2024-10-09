class Solution {
public:
    int minAddToMakeValid(string s) {
        int cnt_open=0,cnt=0;
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
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