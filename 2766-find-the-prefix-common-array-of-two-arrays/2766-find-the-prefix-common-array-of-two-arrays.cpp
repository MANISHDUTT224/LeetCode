class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size();
        vector<int>prefixcommonarray(n),frequency(n+1,0);
        int commoncount=0;
        for(int i=0;i<n;i++){
            if(++frequency[A[i]]==2){
                ++commoncount;
            }
            if(++frequency[B[i]]==2){
                commoncount++;
            }
            prefixcommonarray[i]=commoncount;
        }
        return prefixcommonarray;
    }
};