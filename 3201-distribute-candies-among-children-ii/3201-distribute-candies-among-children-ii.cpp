class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long res=0;
        for(int i=0;i<=min(limit,n);i++){
            if(n-i<=2*limit){
                res+=min(n-i,limit)-max(n-i-limit,0)+1;
            }
        }
        return res;
    }
};