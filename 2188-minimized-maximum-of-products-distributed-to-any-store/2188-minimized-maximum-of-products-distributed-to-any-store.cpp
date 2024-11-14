class Solution {
public:
    bool ispossible(int n,vector<int>&quantities,int mid){
        int steps=0;
        for(int quantity:quantities){
            steps+=quantity/mid;
            if(quantity%mid){
                steps++;
            }
            if(steps>n){
                return 0;
            }
        }
        return steps<=n;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int s=1,e=100000,ans=-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(ispossible(n,quantities,mid)){
                ans=mid;
                e=mid-1;
            }
            else{
            s=mid+1;
            }
        }
        return ans;
    }
};