class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size();
        int sum=0;
        int m=grid[0].size();
        int xorr=0;
        map<int,int>mp;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mp[grid[i][j]]==0){
                sum+=grid[i][j];

                }
                mp[grid[i][j]]++;
                if(mp[grid[i][j]]>1){
                    xorr=grid[i][j];
                }
            }
        }
        int s;
         s=((n*m)*(n*m+1))/2;
        
        return {xorr,abs(s-sum)};
    }
};