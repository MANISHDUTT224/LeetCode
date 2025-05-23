class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>res;
        for(int i=1;i<=numRows;i++){
            vector<int>temp;
            temp.push_back(1);
            int ans=1;
            for(int j=1;j<i;j++){
                ans*=(i-j);
                ans/=j;
                temp.push_back(ans);
            }
            res.push_back(temp);
        }
        return res;
    }
};