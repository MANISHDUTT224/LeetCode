class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shiftarray) {
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
        int n=s.size();
        vector<int>diffarray(n,0);
        for(auto shift:shiftarray){
            if(shift[2]==1){
                diffarray[shift[0]]++;
                if(shift[1]+1<n){
                    diffarray[shift[1]+1]--;
                }
            }
            else{
                diffarray[shift[0]]--;
                if(shift[1]+1<n){
                    diffarray[shift[1]+1]++;
                }
            }
        }
        string result(n,' ');
        int shifts=0;
        for(int i=0;i<n;i++){
             shifts=(shifts+diffarray[i])%26;
             if(shifts<0){
                shifts+=26;
             }
             result[i]='a'+(s[i]-'a'+shifts)%26;
        }
        return result;
    }
};