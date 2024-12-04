class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
        int srclen=str1.size(),tgtlen=str2.size();
        char tgtchar=str2[0];
        int srcidx,tgtidx;
        for(srcidx=0,tgtidx=0;srcidx<srclen&&tgtidx<tgtlen;srcidx++){
            char srchar=str1[srcidx];
            
            if(srchar==tgtchar || srchar+1==tgtchar||(srchar=='z' && tgtchar=='a')){
                tgtchar=str2[++tgtidx];
            }
        }
        return tgtidx==tgtlen;
    }
};