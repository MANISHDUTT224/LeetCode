class Solution {
public:
    int minSteps(int n) {
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
        if(n==0){
            return 1;
        }
        int factor=2;
        int steps=0;
        while(n>1){
            while(n%factor==0){
                steps+=factor;
                n/=factor;
            }
            factor++;
        }
        return steps;
    }
};