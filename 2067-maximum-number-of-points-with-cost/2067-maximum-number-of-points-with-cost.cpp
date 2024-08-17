class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
        int rows=points.size();
        int cols=points[0].size();
        vector<long long>prevrow(cols,0);
        for(int i=0;i<cols;i++){
            prevrow[i]=points[0][i];
        }
        for(int j=0;j<rows-1;j++){
            vector<long long>leftmax(cols,0);
            vector<long long>rightmax(cols,0);
            vector<long long>currow(cols,0);
            leftmax[0]=prevrow[0];
            for(int  k=1;k<cols;k++){
                leftmax[k]=max(leftmax[k-1]-1,prevrow[k]);
            }
            rightmax[cols-1]=prevrow[cols-1];
            for(int k=cols-2;k>=0;k--){
                rightmax[k]=max(rightmax[k+1]-1,prevrow[k]);
            }
            for(int k=0;k<cols;k++){
                currow[k]=max(leftmax[k],rightmax[k])+points[j+1][k];
            }
            prevrow=currow;
        }
        long long ans=LONG_LONG_MIN;
        for(int i=0;i<cols;i++){
            ans=max(prevrow[i],ans);
        }
        return ans;


    }
};