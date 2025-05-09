class Solution {
public:
    int longestMountain(vector<int>& a) {
        int n=a.size();
        int res=0,up=0,down=0;
        for(int i=1;i<n;i++){
            if(down && a[i-1]<a[i]|| a[i-1]==a[i]){
                up=down=0;
            }
            up+=a[i-1]<a[i];
            down+=a[i-1]>a[i];
            if(up && down){
            res=max(res,up+down+1);
            }
        }
        return res;
    }
};