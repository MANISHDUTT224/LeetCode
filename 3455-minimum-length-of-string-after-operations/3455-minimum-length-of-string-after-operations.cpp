class Solution {
public:
    int minimumLength(string s) {
        int totallength=0;
        vector<int>charfreq(26,0);
        for(char c:s){
            charfreq[c-'a']++;
        }
        for(int freq:charfreq){
            if(freq==0){
                continue;
            }
            else if(freq%2==0){
                totallength+=2;
            }
            else{
                totallength++;
            }
        }
        return totallength;
    }
};