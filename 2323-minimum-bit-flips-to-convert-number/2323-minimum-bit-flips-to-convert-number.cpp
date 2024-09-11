class Solution {
public:
    int minBitFlips(int start, int goal) {
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
        int xorr = start ^ goal;
        int res=0;
        while(xorr>0){
            res+=xorr&1;
            xorr>>=1;
        }
        return res;
    }
};