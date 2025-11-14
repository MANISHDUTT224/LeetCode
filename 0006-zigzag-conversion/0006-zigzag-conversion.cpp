class Solution {
public:
    string convert(string s, int numRows) {
        int n=s.size();
        if(numRows==1){
            return s;
        }
        int idx=0,d=1;
        vector<vector<char>>rows(numRows);
        for(int i=0;i<s.size();i++){
            char c=s[i];
            rows[idx].push_back(c);
            if(idx==0){
                d=1;
            }
            else if(idx==numRows-1){
                d=-1;
            }
            idx+=d;
        }
        string res="";
        for(auto row:rows){
            for(auto c:row){
                res+=c;
            }
        }
        return res;
    }
};