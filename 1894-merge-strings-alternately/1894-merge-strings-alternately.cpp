class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i=0,n=word1.size(),j=0,m=word2.size();
        string res="";
        while(i<n && j<m){
            res=res+word1[i]+word2[j];
            i++;
            j++;
        }
        while(i<n){
            res+=word1[i];
            i++;
        }
        while(j<m){
            res+=word2[j];
            j++;
        }
        return res;

    }
};