class Solution {
public:
    bool isvow(char c){
        return c=='a'||c=='i'|c=='o'||c=='e'||c=='u';
    }
    int maxFreqSum(string s) {
        map<int,int>mp;
        for(auto it:s){
            mp[it]++;

        }
        int maxconsfreq=0,maxvowfreq=0;
        for(auto it:mp){
            if(isvow(it.first)){
                maxvowfreq=max(maxvowfreq,it.second);
            }
            else{
                maxconsfreq=max(maxconsfreq,it.second);
            }
        }
        return maxvowfreq+maxconsfreq;
    }
};