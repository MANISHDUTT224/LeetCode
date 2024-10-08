class Solution {
public:
    int minSwaps(string s) {
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
        int cntopen=0,cntclose=0,cnt=0;
        for(auto c:s){
            if(c=='['){
                cntopen++;
            }
            else{
                cntclose++;
                if(cntopen<cntclose){
                    cnt++;
                    cntclose--;
                    cntopen++;
                }
            }
        }
        return cnt;
    }
};