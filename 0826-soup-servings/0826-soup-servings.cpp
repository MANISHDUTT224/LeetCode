class Solution {
    double dp[201][201];
public:
    int m(int x){
        return max(x,0);
    }
    double f(int A,int B){
        return 0.25*(dp[m(A-4)][B]+dp[m(A-3)][m(B-1)]+dp[m(A-2)][m(B-2)]+dp[m(A-1)][m(B-3)]);
    }
    double soupServings(int n) {
        if(n>5000){
            return 1;
        }
        int N=ceil(n/25.0);
        fill(dp[0],dp[0]+N+1,1);
        for(int i=1;i<=N;i++){
            fill(dp[i],dp[i]+N+1,0);
        }
        dp[0][0]=0.5;
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                dp[i][j]=f(i,j);
            }
        }
        return dp[N][N];
    }
};