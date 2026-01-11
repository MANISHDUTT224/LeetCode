class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
       if(matrix.empty()||matrix[0].empty()){
        return 0;
       }
       int r=matrix.size(),c=matrix[0].size();
       int mA=0;
       vector<int> heights(c+1,0);
       for(auto row:matrix){
        for(int i=0;i<c;i++){
            heights[i]=(row[i]=='1')?heights[i]+1:0;
       }
       int n=heights.size();
       for(int i=0;i<n;i++){
        for(int j=i,minh=INT_MAX;j<n;j++){
            minh=min(minh,heights[j]);
            int a=minh*(j-i+1);
            mA=max(mA,a);
        }
       }        
       }
       return mA;
    }
};