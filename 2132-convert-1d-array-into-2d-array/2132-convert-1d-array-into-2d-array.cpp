class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
       
        vector<vector<int>> ans;
        if((m*n)<original.size()){
            return ans;
        }
         if((m*n)>original.size()){
            return ans;
        }
        int index=0;
        for(int i=0;i<m;i++){
            vector<int> a;
            for(int i=0;i<n;i++){
                a.push_back(original[index++]);
            }
            ans.push_back(a);
        }
        return ans;
    }
};