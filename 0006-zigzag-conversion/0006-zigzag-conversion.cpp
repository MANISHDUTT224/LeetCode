class Solution {
public:
    string convert(string s, int numRows) {
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
        int idx=0,d=1;
        if(numRows==1){
            return s;
        }
        vector<vector<char>>rows(numRows);
        for(char c:s){
            rows[idx].push_back(c);
            if(idx==0){
                d=1;
            }
            else if(idx==numRows-1){
                d=-1;
            }
            idx+=d;
        }
        string result;
        for(auto row:rows){
            for(char c:row){
                result+=c;
            }
        }
        return result;
    }
};