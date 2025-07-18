class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int>check(26,0);
        int cnt=0;
        for(char c:sentence){
            check[c-'a']++;
            if(check[c-'a']==1){
                cnt++;
            }
        }
        return cnt==26;
    }
};